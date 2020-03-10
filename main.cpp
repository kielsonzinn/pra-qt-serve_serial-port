#include <QCoreApplication>

#include <QDebug>
#include <QSerialPort>

int main( int argc, char* argv[] ) {

    QCoreApplication app(argc, argv);

    QSerialPort* port = new QSerialPort( "/dev/ttyACM0" );
    port->setBaudRate( QSerialPort::BaudRate::Baud115200, QSerialPort::AllDirections );
    port->setParity( QSerialPort::Parity::NoParity );
    port->setStopBits( QSerialPort::StopBits::OneStop );
    port->setDataBits( QSerialPort::DataBits::Data8 );

    QObject::connect( port, &QSerialPort::readyRead, [&]() {
        QByteArray readAll = port->readAll();
        qCritical() << "[READ_ALL] " << readAll;
    } );

    QObject::connect( port, &QSerialPort::errorOccurred, [&]( QSerialPort::SerialPortError error ) {
        qCritical() << "[ERROR]" << error;
    } );

    if ( !port->open( QSerialPort::ReadWrite ) ) {
        qCritical() << "port no open";
    }

    return app.exec();

}
