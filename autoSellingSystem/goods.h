#ifndef GOODS_H
#define GOODS_H

#include <QObject>

class Goods
{
    private:
    QString id;
    QString name;
    QString imgPath;
    QString description;
	std::vector<QString> branch;
    std::vector<QString> unitPrice;
	std::vector<QString> resQuatity;
	public:
        Goods( QString id, QString name, QString imgPath, QString description, std::vector<QString> branch, std::vector<QString> unitPrice, std::vector<QString> resQuatity );
        QString getId(){return id;}
        QString getName(){return name;}
        QString getImgPath(){return imgPath;}
        QString getDescription(){return description;}
        std::vector<QString> getBranch(){return branch;}
        std::vector<QString> getUnitPrice(){return unitPrice;}
        std::vector<QString> getResQuatity(){return resQuatity;}
		QString getBranchSimple();
		QString getUnitPriceSimple();
		QString getResQuatitySimple();
};

#endif // GOODS_H
