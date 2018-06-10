#ifndef CUSTOMERSMODEL_H
#define CUSTOMERSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "autoSellingSystem/customers.h"

class CustomersModel: public QAbstractListModel
{
    Q_OBJECT

    public:
        enum CustomersRoles {
            NameRole = Qt::UserRole + 1,
            SexRole, ImgPathRole, TelephoneRole
        };

        void insertCustomer( QString name, QString sex, QString imgPath, QString tel );
        QHash<int, QByteArray> roleNames() const;
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    private:
         std::vector <Customers> myData;
};

#endif // CUSTOMERSMODEL_H
