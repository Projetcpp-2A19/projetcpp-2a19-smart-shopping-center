#include "arduino.h"
#include <QSerialPortInfo>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>

Arduino::Arduino()
{
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
    return serial;
}

int Arduino::connect_arduino()
{
    // Recherche du port Arduino parmi les ports disponibles
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        // On suppose que n'importe quel Arduino connecté pourra être détecté
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            // Nous ne spécifions pas les IDs exacts pour la détection mais nous vérifions la présence d'un identifiant USB d'Arduino
            qDebug() << "Arduino détecté sur le port:" << serial_port_info.portName();
            arduino_port_name = serial_port_info.portName();
            arduino_is_available = true;
            break; // Si un Arduino est trouvé, on s'arrête
        }
    }

    if (!arduino_is_available) {
        qDebug() << "Aucun Arduino détecté.";
        return -1; // Aucun Arduino trouvé
    }

    // Configuration de la communication série
    serial->setPortName(arduino_port_name);
    if (serial->open(QSerialPort::ReadWrite)) {
        serial->setBaudRate(QSerialPort::Baud9600); // Débit : 9600 bits/s
        serial->setDataBits(QSerialPort::Data8); // Longueur des données : 8 bits
        serial->setParity(QSerialPort::NoParity); // 1 bit de parité optionnel
        serial->setStopBits(QSerialPort::OneStop); // Nombre de bits de stop : 1
        serial->setFlowControl(QSerialPort::NoFlowControl); // Pas de contrôle de flux

        qDebug() << "Connexion réussie au port:" << arduino_port_name;
        return 0; // Connexion réussie
    } else {
        qDebug() << "Erreur lors de l'ouverture du port série:" << serial->errorString();
        return 1; // Impossible d'ouvrir le port
    }
}

/*int Arduino::close_arduino()
{
    if (serial->isOpen()) {
        serial->close();
        qDebug() << "Port série fermé.";
        return 0; // Port fermé avec succès
    }
    qDebug() << "Le port série est déjà fermé.";
    return 1; // Le port était déjà fermé
}*/

QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable()) {
        data = serial->readAll(); // Récupérer les données reçues
        return data;
    } else {
        qDebug() << "Aucune donnée à lire depuis Arduino.";
        return QByteArray();
    }
}

void Arduino::write_to_arduino(QByteArray d)
{
    if (serial->isWritable()) {
        serial->write(d); // Envoyer des données vers Arduino
        qDebug() << "Données envoyées à Arduino:" << d;
    } else {
        qDebug() << "Impossible d'écrire sur le port série.";
    }
}
