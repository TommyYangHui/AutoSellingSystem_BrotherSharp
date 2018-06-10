#include "autoSellingSystem/goods.h"
#include <cmath>

Goods::Goods( QString id, QString name, QString imgPath, QString description, std::vector<QString> branch, std::vector<QString> unitPrice, std::vector<QString> resQuatity )
{
    this->id = id;
    this->name = name;
    this->imgPath = imgPath;
    this->description = description;
    this->branch = branch;
    this->unitPrice = unitPrice;
    this->resQuatity = resQuatity;
}

QString Goods::getBranchSimple()
{
    QString tv_s;
    tv_s = "";
    for ( int i = 0; i < branch.size(); i++ )
    {
        tv_s += "• " + branch[i] + "\n";

    }
    return tv_s;
}

QString Goods::getUnitPriceSimple()
{
    QString tv_s;
    tv_s = "";
    for ( int i = 0; i < unitPrice.size(); i++ )
    {
        tv_s += "• " + unitPrice[i] + "\n";

    }
    return tv_s;
}

QString Goods::getResQuatitySimple()
{
    QString tv_s;
    tv_s = "";
    for ( int i = 0; i < resQuatity.size(); i++ )
    {
        tv_s += "• " + resQuatity[i] + "\n";

    }
    return tv_s;
}
