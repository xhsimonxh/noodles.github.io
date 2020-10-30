#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"treemodel.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

	
     TreeModel *model=new TreeModel();
	 model->setHeaderData(1,Qt::Horizontal,QVariant("xfz"));

	 //model->rootItem=new TreeItem("root");
	 model->addElement(new TreeItem("f1"));
	 model->addElement(new TreeItem("f2"));
	 model->addElement(new TreeItem("f3"));
	 ui->treeView->setWindowTitle("xxx");
    //model->rootItem=itemParent;
    ui->treeView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItem()
{


}
void MainWindow::removeItem()
{


}
void MainWindow::updateActions()
{


}

void MainWindow::setData()
{

}
