#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"treeitem.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void updateActions();
    void setData();
private slots:
    void addItem();
    void removeItem();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
