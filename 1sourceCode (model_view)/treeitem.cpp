#include "treeitem.h"
#include<assert.h>
TreeItem::TreeItem()
{
	parentItem = (0);
}

int TreeItem::getChildIndex(const TreeItem*child)
{

    for (size_t i = 0; i<childItems.size(); ++i)
        if (childItems[i] == child)
                return static_cast<int>(i);

        return -1;

}
int TreeItem::getIndex() const
{
    if(parentItem)
    {
        return parentItem->getChildIndex(this);
    }
    else
    {
        return -1;
    }
    //return (parentItem ? parentItem->getChildIndex(this) : -1);
}

TreeItem *TreeItem::getChild(int childPos) const
{
    return (childPos < childCount() ? childItems[childPos] : 0);
}

//int TreeItem::childCount() const
//{
//    return childItems.size();
//}

bool TreeItem::addChild(TreeItem* child, int insertIndex/*=-1*/)
{
    if (!child)
    {
        assert(false);
        return false;
    }
    if (std::find(childItems.begin(), childItems.end(), child) != childItems.end())
    {

        return false;
    }


    //insert child
    try
    {
        if (insertIndex < 0 || static_cast<size_t>(insertIndex) >= childItems.size())
            childItems.push_back(child);
        else
            childItems.insert(childItems.begin() + insertIndex, child);
    }
    catch (const std::bad_alloc&)
    {
        //not enough memory!
        return false;
    }



    return true;
}

void TreeItem::removeChild(int pos)
{
    TreeItem*child=childItems[pos];
    delete child;
}


