#include "autoSellingSystem/customersModel.h"
#include<QDateTime>
#include<QDebug>

//insert customer's and order's info into a database
void CustomersModel::insertCustomer( QString name, QString sex, QString imgPath, QString tel )
{
    beginResetModel();
    Customers *tp_customer;
    tp_customer = new Customers( name, sex, imgPath, tel );
	qDebug( "Create Customer\n" );
    this->myData.push_back( *tp_customer );
	delete( tp_customer );
	qDebug( "delete Customer\n");
    endResetModel();
    qDebug("Size of Clients vector is now %d\n",myData.size());
}

QHash<int, QByteArray> CustomersModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[SexRole] = "sex";
    roles[ImgPathRole] = "image";
    roles[TelephoneRole] = "telephone";

    return roles;
}

int CustomersModel::rowCount(const QModelIndex &parent) const
{
    return myData.size();
}

QVariant CustomersModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (myData.size()>row && row>=0)
    {
        Customers i = myData[row];
        switch (role)
        {
        case NameRole: return i.getName();
        case SexRole: return i.getSex();
        case ImgPathRole: return i.getImgPath();
        case TelephoneRole: return i.getTel();
        default: return QVariant();
        }
    }
    else
    {
        QVariant qv;
        return qv;
    }
}
