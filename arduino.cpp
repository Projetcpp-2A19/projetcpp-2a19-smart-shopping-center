#include "arduino.h"
#include <QDebug>

int Arduino::connect_arduino()
{
    // Recherche du port sur lequel la carte Arduino identifiée par arduino_uno_vendor_id est connectée
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts()) {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier()) {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id &&
                serial_port_info.productIdentifier() == arduino_uno_product_id) {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    qDebug() << "arduino_port_name is :" << arduino_port_name;

    if (arduino_is_available) { // Configuration de la communication série
        serial = new QSerialPort;
        serial->setPortName(arduino_port_name);
        if (serial->open(QSerialPort::ReadWrite)) {
            serial->setBaudRate(QSerialPort::Baud9600);        // Débit : 9600 bits/s
            serial->setDataBits(QSerialPort::Data8);           // Longueur des données : 8 bits
            serial->setParity(QSerialPort::NoParity);          // Bit de parité : aucun
            serial->setStopBits(QSerialPort::OneStop);         // Nombre de bits de stop : 1
            serial->setFlowControl(QSerialPort::NoFlowControl);// Pas de contrôle de flux
            return 0;
        }
        return 1; // Erreur d'ouverture
    }

    return -1; // Arduino non trouvé
}
int Arduino::close_arduino()
{
    if (serial->isOpen()) {
        serial->close();
        return 0; // Succès
    }
    return 1; // Échec
}
QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable()) {
        data = serial->readAll();
        return data;
    }
    return QByteArray();
}
int Arduino::write_to_arduino(QByteArray d)
{
    if (serial->isWritable()) {
        serial->write(d);
        return 0; // Succès
    } else {
        qDebug() << "Port série non accessible en écriture";
        return 1; // Erreur
    }
}
