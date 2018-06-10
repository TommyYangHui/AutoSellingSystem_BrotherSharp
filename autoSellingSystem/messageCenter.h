#ifndef MESSAGE_CENTER_H
#define MESSAGE_CENTER_H
#include <QObject>
#include "autoSellingSystem/goodsModel.h"
#include "autoSellingSystem/customersModel.h"

class MessageCenter : public QObject
{

    Q_OBJECT
    Q_PROPERTY( GoodsModel* goodsModel READ goodsModel WRITE setGoodsModel NOTIFY goodsModelChanged )
    Q_PROPERTY( CustomersModel* customersModel READ customersModel WRITE setCustomersModel NOTIFY customersModelChanged )

    public:
         MessageCenter( QObject *parent=0 );
         void setGoodsModel( GoodsModel* pGood )
         {
             _goodsModel = pGood;
             emit goodsModelChanged();
         }
         void setCustomersModel ( CustomersModel* pCustomer )
         {
             _customersModel = pCustomer;
             emit customersModelChanged();
         }

         GoodsModel* goodsModel()
         {
             return _goodsModel;
         }
         CustomersModel* customersModel()
         {
             return _customersModel;
         }


    private:
        GoodsModel *_goodsModel;
        CustomersModel *_customersModel;


    signals:
        void goodsModelChanged();
        void customersModelChanged();

    public slots:
		void insertItem( QString name, QString imgPath, QString description, QVariantList branch, QVariantList unitPrice, QVariantList resQuatity );
        void deleteItem(QString id);
		void changeItem( QString id, QString name, QString imgPath, QString description, QVariantList branch, QVariantList unitPrice, QVariantList resQuatity );

};

#endif // MESSAGE_CENTER_H

