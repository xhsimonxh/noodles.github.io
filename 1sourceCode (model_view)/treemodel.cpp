#include "treemodel.h"
#include<assert.h>
TreeModel::TreeModel()
{
    rootItem=new TreeItem("root");
    /*addElement(new TreeItem("f1"));
    addElement(new TreeItem("f2"));
    addElement(new TreeItem("f3"));*/
    //rootItem->addChild(new TreeItem("f1"));
   // rootItem->addChild(new TreeItem("f2"));
    //rootItem->addChild(new TreeItem("f3"));
}
int TreeModel::columnCount(const QModelIndex & /* parent */) const
{
    return 1;
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    TreeItem *parentItem = getItem(parent);

    return parentItem->childCount();
}

TreeItem *TreeModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    TreeItem *item = getItem(index);

    return QVariant(item->name);
}

bool TreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
   if (role == Qt::EditRole)
    {
    TreeItem *item = getItem(index);
    item->name=value.toString();

    emit dataChanged(index, index);
    return true;
    }

}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();
    //获取子节点也可以这样表达
    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());//
    if (!childItem)
        {
            //assert(false);
            return QModelIndex();
        }
   // TreeItem *childItem = getItem(index);
    TreeItem *parentItem = childItem->getParent();
  
	if (!parentItem || parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->getIndex(), 0, parentItem);
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parentIndex) const
{

    if(!hasIndex(row, column, parentIndex))
    {
        return QModelIndex();//父节点的索引
    }

    TreeItem *parent=(parentIndex.isValid()?static_cast<TreeItem*>(parentIndex.internalPointer()):rootItem);
    if(!parent)
    {
        return QModelIndex();
    }
    TreeItem *child=parent->getChild(row);

    return child?createIndex(row,column,child):QModelIndex();
}

QModelIndex TreeModel::index(TreeItem* object)
{


    if (object == rootItem)
    {
        return QModelIndex();
    }

    TreeItem* parent = object->getParent();
    if (!parent)
    {
        //ccLog::Error(QString("An error occurred while creating DB tree index: object '%1' has no parent").arg(object->getName()));
        return QModelIndex();
    }

    int pos = parent->getChildIndex(object);

    return createIndex(pos, 0, object);
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}

void TreeModel::addElement(TreeItem* object, bool autoExpand)
 {
    Q_UNUSED(autoExpand)
    if (!rootItem)
        {
            assert(false);
            return;
        }
    if (!object)
        {
            assert(false);
            return;
        }


    TreeItem *parent=object->getParent();
    if(!parent)//若非根节点，怎么加？
    {
        parent=rootItem;
        rootItem->addChild(object);
    }
	QString name=parent->name;

    QModelIndex insertNodeIndex = index(parent);
    int childPos = parent->getChildIndex(object);

    beginInsertRows(insertNodeIndex, childPos, childPos);

    endInsertRows();

 }

void TreeModel::removeElement(TreeItem* object)
{

    TreeItem *parent=object->getParent();
    int childPos=parent->getChildIndex(object);
    beginRemoveRows(index(parent), childPos, childPos);

    parent->removeChild(childPos);

    endRemoveRows();
}
