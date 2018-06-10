#include "autoSellingSystem/messageCenter.h"
#include<QDateTime>
#include<QDebug>

MessageCenter::MessageCenter(QObject *parent) : QObject(parent)
{
    _goodsModel = new GoodsModel();
    _customersModel = new CustomersModel();

    QString description1, description2, description3, description4, description5, description6, description7, description8, description9;
	description1 = "RIO cocktail is a cocktail of the brand rio. The main ingredients are juice, brandy, rum and so on. The wine uses fresh frozen technology to purify fruit juices to meet the needs of adult consumers.";
	description2 = " Product formula: water, sugar, honey, carbon dioxide, citric acid, alkaline electrolyte (potassium, sodium, calcium, magnesium), sodium benzoate, acesulfame, stevioside, sunset yellow, edible flavor";
	description3 = "Honey lemonade is a drink made from honey and lemon as its main ingredients. Sweet and sour taste, with Sheng Jin, weight loss, thirst quencher, Qushu, beauty, beauty and other effects.";
	description4 = "Ingredients: water, white granulated sugar, orange meat, concentrated orange juice, citric acid, edible essence, sodium citrate, vitamin C, B-carotene, orange meat average content: 5 g/100 ml, orange juice content not less than 10%";
	description5 = "Based on fruit and vegetable juice, add water, sugar, acid or spices";
    description6 = "Farmer screams (fiber drinks) is a brand new functional beverage. Different from vitamins and minerals supplemented by other brands of beverages, the “Scream” series is a nutritional supplement for plants.";
	description7 = "Coffee is a beverage made from roasted coffee beans. It is also a popular drink in the world with cocoa and tea";
    description8 = "Pineapple juice is a kind of drink made from a combination of pineapple and salt for the treatment of heat and thirst. According to their own preferences, add their favorite accessories, different accessories, of course, taste and efficacy are also different.";
	description9 = " Ingredients: 8 to 9 horseshoes (auxiliaries) Excipients: 2 spoons of honey";

    QVariantList branch1, branch2, branch3, branch4, branch5, branch6, branch7, branch8, branch9;
    branch1.append("Lemon");
    branch1.append("Peach");
    branch1.append("Orange");
    branch1.append("Pomelo");
    branch1.append("Original");

    branch2.append("Original");

    branch3.append("Original");

    branch4.append("Original");
    branch4.append("Fruit");

    branch5.append("Orginal");
    branch5.append("Orange");
    branch5.append("Peach");

    branch6.append("Orginal");

    branch7.append("Orginal");

    branch8.append("Orginal");

    branch9.append("Orginal");

    QVariantList unitPrice1, unitPrice2, unitPrice3, unitPrice4, unitPrice5, unitPrice6, unitPrice7, unitPrice8, unitPrice9;
    unitPrice1.append("5");
    unitPrice2.append("6");
    unitPrice3.append("7");
    unitPrice4.append("8");
    unitPrice5.append("4");
    unitPrice6.append("6");
    unitPrice7.append("10");
    unitPrice8.append("10");
    unitPrice9.append("8");

    QVariantList resQuatity1, resQuatity2, resQuatity3, resQuatity4, resQuatity5, resQuatity6, resQuatity7, resQuatity8, resQuatity9;
    resQuatity1.append(10);
    resQuatity1.append(10);
    resQuatity1.append(10);
    resQuatity1.append(10);
    resQuatity1.append(10);

    resQuatity2.append(20);

    resQuatity3.append(10);

    resQuatity4.append(9);
    resQuatity4.append(7);

    resQuatity5.append(3);
    resQuatity5.append(3);
    resQuatity5.append(3);

    resQuatity6.append(13);

    resQuatity7.append(10);

    resQuatity8.append(10);

    resQuatity9.append(10);

    insertItem( "RIO", "../images/RIO.jpeg", description1, branch1, unitPrice1, resQuatity1 );
    insertItem( "cool", "../images/cool.jpeg", description2, branch2, unitPrice2, resQuatity2 );
    insertItem( "lemonate", "../images/lemonate.jpg", description3, branch3, unitPrice3, resQuatity3 );
    insertItem( "juice", "../images/juice.jpeg", description4, branch4, unitPrice4, resQuatity4 );
    insertItem( "hotdrink", "../images/hotdrink.jpg", description5, branch5, unitPrice5, resQuatity5 );
    insertItem( "scream", "../images/scream.jpg", description6, branch6, unitPrice6, resQuatity6 );
    insertItem( "coffee", "../images/coffee.jpeg", description7, branch7, unitPrice7, resQuatity7 );
    insertItem( "pineApple", "../images/pineapple.jpeg", description8, branch8, unitPrice8, resQuatity8 );
    insertItem( "yeos", "../images/yeos.jpeg", description9, branch9, unitPrice9, resQuatity9 );

}

void MessageCenter::insertItem( QString name, QString imgPath, QString description, QVariantList branch, QVariantList unitPrice, QVariantList resQuatity )
{
    std::vector<QString> tv_branch;
    std::vector<QString> tv_unitPrice;
    std::vector<QString> tv_resQuatity;

    for ( int i = 0; i < branch.size(); i++)
        tv_branch.push_back( branch[i].toString() );
    for ( int i = 0; i < unitPrice.size(); i++ )
        tv_unitPrice.push_back( unitPrice[i].toString() );
    for ( int i = 0; i < resQuatity.size(); i++ )
        tv_resQuatity.push_back( resQuatity[i].toString() );

    int tv_id = rand() % 10000000 + 1;
    QString tv_id2 = QString::number( tv_id );
    qDebug() << tv_id2;

    _goodsModel->insertItem( tv_id2, name, imgPath, description, tv_branch, tv_unitPrice, tv_resQuatity );
}

void MessageCenter::deleteItem( QString id ){

    _goodsModel->deleteItem(id);
}

void MessageCenter::changeItem( QString id, QString name, QString imgPath, QString description, QVariantList branch, QVariantList unitPrice, QVariantList resQuatity )
{
    std::vector<QString> tv_branch;
    std::vector<QString> tv_unitPrice;
    std::vector<QString> tv_resQuatity;

    for ( int i = 0; i < branch.size(); i++)
        tv_branch.push_back( branch[i].toString() );
    for ( int i = 0; i < unitPrice.size(); i++ )
        tv_unitPrice.push_back( unitPrice[i].toString() );
    for ( int i = 0; i < resQuatity.size(); i++ )
        tv_resQuatity.push_back( resQuatity[i].toString() );

    _goodsModel->changeItem(id, name, imgPath,description, tv_branch, tv_unitPrice, tv_resQuatity );
}
