#include <motortest.h>
#include <QDebug>
#include <getopt.h>
#include <iostream>
using namespace std;

MotorTest::MotorTest(QObject *parent) :
    QObject(parent)
{
    bool keluar = false;
    char key;
    while(!keluar) {
        cout <<endl<< "Tekan [\"q\"] atau [\"Q\"] untuk keluar :  ";
        cout <<endl<< "Tekan [\"g\"] atau [\"G\"] untuk keluar :  ";
        cout <<endl<< "Tekan [\"m\"] atau [\"M\"] untuk keluar :  ";
        cout <<endl<< "Tekan [\"r\"] atau [\"R\"] untuk keluar :  ";
        cout <<endl<< "Tekan [\"l\"] atau [\"L\"] untuk keluar :  ";
        cout <<endl<< "PERINTAH :";
        do {

            cin.get(key);
        }
        while (isspace(key));
            if ((key == 'q') || (key== 'Q')) {
                keluar = true;
                if (keluar == true){
                    this->stop();
                }
                exit(0);
            }
            else if ((key == 'g') || (key== 'G')){
                this->motorMaju();
            }
            else if ((key == 'm') || (key== 'M')){
                this->motorMundur();
            }
            else if ((key == 'r') || (key== 'R')){
                this->motorKanan();
            }
            else if ((key == 'l') || (key== 'L')){
                this->motorKiri();
            }
            else{

            }
    }
}

void MotorTest::motorKanan(){
    //motor kanan
    LibGPIOjs* gpio4 = new LibGPIOjs("4"); //kiri
    LibGPIOjs* gpio17 = new LibGPIOjs("17"); //kanan
    LibGPIOjs* gpio27 = new LibGPIOjs("27"); //saklar motor
    //motor kiri
    LibGPIOjs* gpio18 = new LibGPIOjs("18"); //saklar motor
    LibGPIOjs* gpio23 = new LibGPIOjs("23"); //kiri
    LibGPIOjs* gpio24 = new LibGPIOjs("24"); //kanan

    //export gpio motor kanan
    gpio4->exportgpio();
    gpio17->exportgpio();
    gpio27->exportgpio();

    //export gpio motor kiri
    gpio18->exportgpio();
    gpio23->exportgpio();
    gpio24->exportgpio();

    //set direksi pin motor Kanan menjadi output
    gpio4->setdirgpio("out");
    gpio17->setdirgpio("out");
    gpio27->setdirgpio("out");

    //set direksi pin motor Kiri menjadi output
    gpio18->setdirgpio("out");
    gpio23->setdirgpio("out");
    gpio24->setdirgpio("out");

    // motor kanan
    gpio4->setvalgpio("0");
    gpio17->setvalgpio("1");
    gpio27->setvalgpio("1"); //nyalakan motor
    //motor kiri
    gpio23->setvalgpio("0");
    gpio24->setvalgpio("1");
    gpio18->setvalgpio("1"); //nyalakan motor

    qDebug()<<"motor Kanan Aktif";
    this->stop();

}

void MotorTest::motorKiri(){
    //motor kanan
    LibGPIOjs* gpio4 = new LibGPIOjs("4"); //kiri
    LibGPIOjs* gpio17 = new LibGPIOjs("17"); //kanan
    LibGPIOjs* gpio27 = new LibGPIOjs("27"); //saklar motor
    //motor kiri
    LibGPIOjs* gpio18 = new LibGPIOjs("18"); //saklar motor
    LibGPIOjs* gpio23 = new LibGPIOjs("23"); //kiri
    LibGPIOjs* gpio24 = new LibGPIOjs("24"); //kanan

    gpio4->exportgpio();
    gpio17->exportgpio();
    gpio27->exportgpio();


    gpio18->exportgpio();
    gpio23->exportgpio();
    gpio24->exportgpio();

    //set direksi pin motor Kanan menjadi output
    gpio4->setdirgpio("out");
    gpio17->setdirgpio("out");
    gpio27->setdirgpio("out");

    //set direksi pin motor Kiri menjadi output
    gpio18->setdirgpio("out");
    gpio23->setdirgpio("out");
    gpio24->setdirgpio("out");

    //motor kanan
    gpio4->setvalgpio("1");
    gpio17->setvalgpio("0");
    gpio27->setvalgpio("1"); //nyalakan motor
    //motor kiri
    gpio23->setvalgpio("1");
    gpio24->setvalgpio("0");
    gpio18->setvalgpio("1"); //nyalakan motor

    qDebug()<<"motor kiri Aktif";
    this->stop();
}

void MotorTest::motorMaju(){
    //motor kanan
    LibGPIOjs* gpio4 = new LibGPIOjs("4"); //kiri
    LibGPIOjs* gpio17 = new LibGPIOjs("17"); //kanan
    LibGPIOjs* gpio27 = new LibGPIOjs("27"); //saklar motor
    //motor kiri
    LibGPIOjs* gpio18 = new LibGPIOjs("18"); //saklar motor
    LibGPIOjs* gpio23 = new LibGPIOjs("23"); //kiri
    LibGPIOjs* gpio24 = new LibGPIOjs("24"); //kanan

    gpio4->exportgpio();
    gpio17->exportgpio();
    gpio27->exportgpio();


    gpio18->exportgpio();
    gpio23->exportgpio();
    gpio24->exportgpio();

    //set direksi pin motor Kanan menjadi output
    gpio4->setdirgpio("out");
    gpio17->setdirgpio("out");
    gpio27->setdirgpio("out");

    //set direksi pin motor Kiri menjadi output
    gpio18->setdirgpio("out");
    gpio23->setdirgpio("out");
    gpio24->setdirgpio("out");

    //memajukan motor
    gpio4->setvalgpio("1");
    gpio17->setvalgpio("0");
    gpio27->setvalgpio("1"); //nyalakan motor

    gpio23->setvalgpio("0");
    gpio24->setvalgpio("1");
    gpio18->setvalgpio("1"); //nyalakan motor

    qDebug()<<"Mari Jalan :v ";
    this->stop();
}

void MotorTest::motorMundur(){
    //motor kanan
    LibGPIOjs* gpio4 = new LibGPIOjs("4"); //kiri
    LibGPIOjs* gpio17 = new LibGPIOjs("17"); //kanan
    LibGPIOjs* gpio27 = new LibGPIOjs("27"); //saklar motor
    //motor kiri
    LibGPIOjs* gpio18 = new LibGPIOjs("18"); //saklar motor
    LibGPIOjs* gpio23 = new LibGPIOjs("23"); //kiri
    LibGPIOjs* gpio24 = new LibGPIOjs("24"); //kanan

    gpio4->exportgpio();
    gpio17->exportgpio();
    gpio27->exportgpio();


    gpio18->exportgpio();
    gpio23->exportgpio();
    gpio24->exportgpio();

    //set direksi pin motor Kanan menjadi output
    gpio4->setdirgpio("out");
    gpio17->setdirgpio("out");
    gpio27->setdirgpio("out");

    //set direksi pin motor Kiri menjadi output
    gpio18->setdirgpio("out");
    gpio23->setdirgpio("out");
    gpio24->setdirgpio("out");

    //mundurkan motor
    gpio4->setvalgpio("0");
    gpio17->setvalgpio("1");
    gpio27->setvalgpio("1"); //nyalakan motor

    gpio23->setvalgpio("1");
    gpio24->setvalgpio("0");
    gpio18->setvalgpio("1"); //nyalakan motor

    qDebug()<<"motor Mundur Pasang Mata :v ";
    this->stop();
}

void MotorTest::stop(){
                    //motor kanan
                    LibGPIOjs* gpio4 = new LibGPIOjs("4"); //kiri
                    LibGPIOjs* gpio17 = new LibGPIOjs("17"); //kanan
                    LibGPIOjs* gpio27 = new LibGPIOjs("27"); //saklar motor
                    //motor kiri
                    LibGPIOjs* gpio18 = new LibGPIOjs("18"); //saklar motor
                    LibGPIOjs* gpio23 = new LibGPIOjs("23"); //kiri
                    LibGPIOjs* gpio24 = new LibGPIOjs("24"); //kanan

                    gpio4->exportgpio();
                    gpio17->exportgpio();
                    gpio27->exportgpio();


                    gpio18->exportgpio();
                    gpio23->exportgpio();
                    gpio24->exportgpio();

                    //set direksi pin motor Kanan menjadi output
                    gpio4->setdirgpio("out");
                    gpio17->setdirgpio("out");
                    gpio27->setdirgpio("out");

                    //set direksi pin motor Kiri menjadi output
                    gpio18->setdirgpio("out");
                    gpio23->setdirgpio("out");
                    gpio24->setdirgpio("out");

                    //matikan motor
                    gpio4->setvalgpio("0");
                    gpio17->setvalgpio("0");
                    gpio27->setvalgpio("0");

                    gpio23->setvalgpio("0");
                    gpio24->setvalgpio("0");
                    gpio18->setvalgpio("0");

                    this->kembalikanData();
}

void MotorTest::kembalikanData(){
    LibGPIOjs* gpio4 = new LibGPIOjs("4");
    LibGPIOjs* gpio17 = new LibGPIOjs("17");
    LibGPIOjs* gpio27 = new LibGPIOjs("27");
    LibGPIOjs* gpio18 = new LibGPIOjs("18");
    LibGPIOjs* gpio23 = new LibGPIOjs("23");
    LibGPIOjs* gpio24 = new LibGPIOjs("24");
    gpio4->unexportgpio();
    gpio17->unexportgpio();
    gpio27->unexportgpio();
    gpio18->unexportgpio();
    gpio23->unexportgpio();
    gpio24->unexportgpio();

    qDebug()<<"unexport gpio berjalan lancar :v";
}
