#include "libgpiojs.h"
#include <QDebug>

LibGPIOjs::LibGPIOjs(QObject *parent) :
    QObject(parent)
{ 
    this->gpionum="";
}

LibGPIOjs::LibGPIOjs(QString no_Gpio){
    this->gpionum = no_Gpio;
}

int LibGPIOjs::exportgpio(){
    const QString p = "/sys/class/gpio/";
    QFile file(p+"export");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << this->gpionum;
        qDebug() <<"GPIO"<< this->gpionum <<"is Active" ;

        return true;
    }
    else {
        return false;
    }
    file.close();

    return 0;
}

int LibGPIOjs::unexportgpio(){
    const QString p = "/sys/class/gpio/";
    QFile file(p+"unexport");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << this->gpionum;

        qDebug() <<"GPIO"<< this->gpionum <<"is Non Active" ;

        return true;
    }
    else{
        return false;
    }
    file.close();

    return 0;
}

int LibGPIOjs::setdirgpio(QString dir){
    const QString p = "/sys/class/gpio/gpio"+this->gpionum+"/";
    QFile file(p+"direction");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << dir;

        if (dir == "out"){
            qDebug() <<"Set direction GPIO"<< this->gpionum <<"is output" ;
        }
        else {
            qDebug()<<"Set direction GPIO"<< this->gpionum << "is input";
        }

        return true;
    }

    else {
        return false;
    }
    return 0;
}

int LibGPIOjs::setvalgpio(QString val){
    const QString p = "/sys/class/gpio/gpio"+this->gpionum+"/";
    QFile file(p+"value");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << val;

        if (val == "1"){
            qDebug() <<"Set Value GPIO"<< this->gpionum <<"is Active" ;
        }
        else {
            qDebug() <<"Set Value GPIO"<< this->gpionum <<"is Non Active" ;
        }
        return true;
    }

    else {
        return false;
    }
    return 0;
}

int LibGPIOjs::getvalgpio(QString &val){
    const QString p = "/sys/class/gpio/gpio"+this->gpionum+"/";
    QFile file(p+"value");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out >> val;
        qDebug() <<"Set Value GPIO"<< this->gpionum <<"is Active" ;

        if(val != "0")
            val = "1";
        else
            val = "0";

        return true;
    }

    else {
        return false;
    }

    return 0;
}
/* //experiment
int LibGPIOjs::tes(QString t){
    const QString p = "/home/igos/Desktop/gpio/gpio"+this->gpionum+"/";
    QFile file(p+"direction");

    if (file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&file);
        out << t;

        if (t == "out"){
            qDebug() <<"Set direction GPIO"<< this->gpionum <<"is output" ;
        }
        else {
            qDebug()<<"Set direction GPIO"<< this->gpionum << "is input";
        }

        return true;
    }

    else {
        return false;
    }

    return 0;
}
*/
QString LibGPIOjs::getgpionum(){
    return this->gpionum;
}




