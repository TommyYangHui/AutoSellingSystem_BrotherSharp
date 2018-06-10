#include "autoSellingSystem/goodsModel.h"

// insert an item into a database
void GoodsModel::insertItem( QString id, QString name, QString imgPath, QString description, std::vector<QString> branch, std::vector<QString> unitPrice, std::vector<QString> resQuatity )
{
    beginResetModel();

    Goods *tp_goods;
    tp_goods = new Goods( id, name, imgPath, description, branch, unitPrice, resQuatity );

    qDebug( "object created\n" );
    this->myData.push_back( *tp_goods );
	delete( tp_goods );
    qDebug( "object delete\n" );
    endResetModel();

    qDebug( "Size of Items vector is now %d\n",myData.size() );
}
//deletes an item from database according to it's unique id
void GoodsModel::deleteItem(QString id){
    int k=0;
    beginResetModel();
    for ( unsigned long j=0;j<myData.size();j++ )
    {
            if ( ((Goods)myData[j]).getId()==id )
            {
               break;
            }
            k++;
    }
    myData.erase(myData.begin() + k);
    endResetModel();
}
//changes item's info
void GoodsModel::changeItem( QString id, QString name, QString imgPath, QString description, std::vector<QString> branch, std::vector<QString> unitPrice, std::vector<QString> resQuatity )
{
    beginResetModel();
    for (unsigned long j=0;j<myData.size();j++)
    {
            if ( ((Goods)myData[j]).getId()==id )
            {
                beginResetModel();
                int id = rand() % 10000000 + 1;
                QString id2 = QString::number( id );

    			Goods *tp_goods;
                tp_goods = new Goods( id2, name, imgPath, description, branch, unitPrice, resQuatity );

    			qDebug( "object created\n" );
	    		this->myData.push_back( *tp_goods );
				delete( tp_goods );
    			qDebug( "object delete\n" );
    			endResetModel();
                break;
            }
    }
}

QHash<int, QByteArray> GoodsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[ImgPathRole] = "image";
    roles[DescriptionRole] = "description";
    roles[BranchRole] = "branch";
    roles[UnitPriceRole] = "unitPrice";
    roles[ResQuatityRole] = "resQuatity";
    return roles;
}

int GoodsModel::rowCount(const QModelIndex &parent) const
{
    return myData.size();
}


QVariant GoodsModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (myData.size()>row && row>=0)
    {
        Goods i = myData[row];
        switch (role)
        {
            case IdRole: return i.getId();
            case NameRole: return i.getName();
            case ImgPathRole: return i.getImgPath();
            case DescriptionRole: return i.getDescription();
            case BranchRole:
            //return QVariant::fromValue( i.getBranch() );
                return i.getBranchSimple();
            case UnitPriceRole:
            //return QVariant::fromValue( i.getUnitPrice() );
                return i.getUnitPriceSimple();
            case ResQuatityRole:
//            return QVariant::fromValue( i.getResQuatity() );
                return i.getResQuatitySimple();
            default: return QVariant();
        }
    }
    else
    {
        QVariant qv;
        return qv;
    }
}
