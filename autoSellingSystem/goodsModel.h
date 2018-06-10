#ifndef GOODSMODEL_H
#define GOODSMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include "autoSellingSystem/goods.h"

class GoodsModel : public QAbstractListModel
{
    Q_OBJECT

    public:
        enum GoodsRoles {
             IdRole = Qt::UserRole + 1,
             NameRole, ImgPathRole, DescriptionRole, BranchRole, UnitPriceRole, ResQuatityRole
        };

        void insertItem( QString id, QString name, QString imgPath, QString description, std::vector<QString> branch, std::vector<QString> unitPrice, std::vector<QString> resQuatity );
        void deleteItem( QString id );
        void changeItem( QString id, QString name, QString imgPath, QString description, std::vector<QString> branch, std::vector<QString> unitPrice, std::vector<QString> resQuatity );
        QHash<int, QByteArray> roleNames() const;
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    private:
       std:: vector <Goods> myData;
};

#endif // GOODSMODEL_H
