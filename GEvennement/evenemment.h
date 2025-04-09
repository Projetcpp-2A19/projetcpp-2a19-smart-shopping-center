#ifndef EVENEMMENT_H
#define EVENEMMENT_H

#include <QObject>
#include <QString>

class Evenemment : public QObject
{
    Q_OBJECT

public:
    explicit Evenemment(QObject *parent = nullptr);
    Evenemment(const Evenemment &);
    Evenemment(Evenemment &&);
    Evenemment &operator=(const Evenemment &);
    Evenemment &operator=(Evenemment &&);
    ~Evenemment();

private:
};

#endif // EVENEMMENT_H
