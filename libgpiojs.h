#ifndef LIBGPIOJS_H
#define LIBGPIOJS_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDataStream>

class LibGPIOjs : public QObject
{
    Q_OBJECT
public:
    LibGPIOjs(QObject *parent = 0);

    LibGPIOjs(QString no_Gpio);
    int exportgpio();
    int unexportgpio();
    int setdirgpio(QString dir);
    int setvalgpio(QString val);
    int getvalgpio(QString &val); //experiment
    QString getgpionum();
    //int tes(QString t); //experiment

private:
     QString gpionum;

signals:

public slots:

};

#endif // LIBGPIOJS_H
