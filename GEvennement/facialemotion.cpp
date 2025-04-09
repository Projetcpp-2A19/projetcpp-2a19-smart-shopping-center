#include "facialemotion.h"
#include <QDebug>
#include <QDir>

FacialEmotion::FacialEmotion(QObject *parent)
    : QObject(parent), modelsLoaded(false)
{
    detector = dlib::get_frontal_face_detector();
}

FacialEmotion::~FacialEmotion()
{
}

bool FacialEmotion::loadModels()
{
    try {
        QString modelPath = QDir::currentPath() + "/shape_predictor_68_face_landmarks.dat";
        dlib::deserialize(modelPath.toStdString()) >> predictor;
        modelsLoaded = true;
        return true;
    } catch (const dlib::serialization_error& e) {
        emit error(QString("Erreur de chargement du modèle: %1").arg(e.what()));
        modelsLoaded = false;
        return false;
    }
}

cv::Mat FacialEmotion::qImageToCvMat(const QImage &image)
{
    switch (image.format()) {
    case QImage::Format_RGB888: {
        cv::Mat mat(image.height(), image.width(), CV_8UC3, 
                   const_cast<uchar*>(image.bits()), image.bytesPerLine());
        cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
        return mat;
    }
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied: {
        cv::Mat mat(image.height(), image.width(), CV_8UC4, 
                   const_cast<uchar*>(image.bits()), image.bytesPerLine());
        cv::Mat mat2;
        cv::cvtColor(mat, mat2, cv::COLOR_BGRA2BGR);
        return mat2;
    }
    default:
        QImage converted = image.convertToFormat(QImage::Format_RGB888);
        cv::Mat mat(converted.height(), converted.width(), CV_8UC3, 
                   const_cast<uchar*>(converted.bits()), converted.bytesPerLine());
        cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR);
        return mat;
    }
}

double FacialEmotion::calculateEmotionScore(const std::vector<dlib::point>& landmarks)
{
    // Points pour la bouche
    double mouthWidth = dlib::length(landmarks[54] - landmarks[48]);
    double mouthHeight = dlib::length(landmarks[57] - landmarks[51]);
    double mouthRatio = mouthWidth / mouthHeight;

    // Points pour les sourcils
    double leftEyebrowHeight = landmarks[24].y() - landmarks[27].y();
    double rightEyebrowHeight = landmarks[19].y() - landmarks[27].y();
    double eyebrowHeight = (leftEyebrowHeight + rightEyebrowHeight) / 2.0;

    // Calcul du score final
    double score = mouthRatio + eyebrowHeight;
    return score;
}

void FacialEmotion::detectEmotion(const QImage &image)
{
    if (!modelsLoaded) {
        emit error(QString("Les modèles ne sont pas chargés"));
        return;
    }

    try {
        cv::Mat cvImg = qImageToCvMat(image);
        dlib::cv_image<dlib::bgr_pixel> dlibImg(cvImg);

        std::vector<dlib::rectangle> faces = detector(dlibImg);
        
        if (faces.empty()) {
            emit emotionDetected(UNKNOWN);
            return;
        }

        dlib::full_object_detection shape = predictor(dlibImg, faces[0]);
        std::vector<dlib::point> landmarks;
        for (unsigned int i = 0; i < shape.num_parts(); ++i) {
            landmarks.push_back(shape.part(i));
        }

        double score = calculateEmotionScore(landmarks);

        if (score > 2.0) {
            emit emotionDetected(HAPPY);
        } else if (score < 1.0) {
            emit emotionDetected(STRESSED);
        } else {
            emit emotionDetected(NEUTRAL);
        }

    } catch (const std::exception& e) {
        emit error(QString("Erreur de détection: %1").arg(e.what()));
    }
}

QString FacialEmotion::getEmotionString(Emotion emotion)
{
    switch (emotion) {
        case HAPPY:
            return "Heureux";
        case STRESSED:
            return "Stressé";
        case NEUTRAL:
            return "Neutre";
        default:
            return "Inconnu";
    }
} 
