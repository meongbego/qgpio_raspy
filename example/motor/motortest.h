#ifndef MOTORTEST_H
#define MOTORTEST_H

#include <QObject>
#include <../../libgpiojs.h>

class MotorTest : public QObject
{
    Q_OBJECT
public:
    MotorTest(QObject *parent = 0);

    void motorMaju();
    void motorMundur();
    void motorKiri();
    void motorKanan();
    void stop();
    void kembalikanData();

signals:

public slots:

};
#endif // MOTORTEST_H
