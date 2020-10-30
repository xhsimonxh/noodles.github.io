#ifndef TREEITEM_H
#define TREEITEM_H

#include<QString>
#include<iostream>
#include<vector>
using namespace std;
struct point
{
   double x,y,z;
};


class TreeItem
{
public:
    TreeItem();
    TreeItem(QString n):name(n),parentItem(0){}
    QString name;
    void setName(QString n){name=n;}
    QString getName(){return name;}

    //****child管理
    //bool addChild();
    //removeChild();
    bool addChild(TreeItem* child, int insertIndex=-1);
    void removeChild(int pos);
    void removeChild(TreeItem *child);//

    //void removeChildren();
    //inline unsigned getChildrenNumber()const{ return childItems.size();}//当前子节点在父节点中位置
    TreeItem *getChild(int num)const;
    int getChildIndex(const TreeItem*child);
    int getIndex() const;
    int childCount() const{return childItems.size();}
    //***parent管理
    inline void setParent(TreeItem *parent){parent=parentItem;}
    inline TreeItem* getParent() const{return parentItem;}
    //数据管理
    //void setData();
    //void deleteData();


     vector<TreeItem*> childItems;
     TreeItem *parentItem;
     vector<point> points;
};

#endif // TREEITEM_H
