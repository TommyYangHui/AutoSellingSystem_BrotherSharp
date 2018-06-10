#ifndef CUSTOMERS_H
#define CUSTOMERS_H

#include <QObject>

class Customers
{
    QString name;
    QString sex;
    QString imgPath;
    QString tel;

    public:
        Customers( QString name, QString sex, QString imgPath, QString tel );
        QString getName(){return name;}
        QString getSex(){return sex;}
        QString getImgPath(){return imgPath;}
        QString getTel(){return tel;}
};

#endif // CUSTOMERS_H
