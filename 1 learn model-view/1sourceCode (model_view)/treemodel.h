#ifndef TREEMODEL_H
#define TREEMODEL_H
#include<QAbstractItemModel>
#include"treeitem.h"
#include<QModelIndex>
using namespace std;
class TreeItem;

class TreeModel:public QAbstractItemModel
{
public:
    TreeModel();
    //TreeModel(TreeItem *item){rootItem=item;}

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
   // QVariant headerData(int section, Qt::Orientation orientation,int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QModelIndex index(TreeItem* object);
    QModelIndex index(int row, int column,
                          const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value,
                    int role = Qt::EditRole) Q_DECL_OVERRIDE;
    //void showContextMenu(const QPoint&);
 //    Qt::DropActions supportedDropActions() const override;
 //    bool dropMimeData(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex& parent) override;
 //    QMap<int,QVariant> itemData(const QModelIndex& index) const override;
 //    Qt::DropActions supportedDragActions() const override { return Qt::MoveAction; }


   void addElement(TreeItem* object, bool autoExpand = true);
   void removeElement(TreeItem* object);
   void removeElements(vector<TreeItem>& objects);
   TreeItem getRootEntity();
   TreeItem *getItem(const QModelIndex &index) const;

   TreeItem *rootItem;
};

#endif // TREEMODEL_H
