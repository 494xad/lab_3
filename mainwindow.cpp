#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtreeview.h"
#include "qfilesystemmodel.h"
#include "qtableview.h"
#include "qboxlayout.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    QFileSystemModel *model = new QFileSystemModel();
    model->setRootPath(QDir::currentPath());
    QTreeView *treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setRootIndex(model->index(QDir::currentPath()));
    QTableView *table = new QTableView(this);
    table->setModel(model);
    table->setRootIndex(model->index(QDir::currentPath()));
    QBoxLayout *boxLayout = new QBoxLayout(QBoxLayout::Direction::LeftToRight, this);
    boxLayout->addWidget(treeView);
    boxLayout->addWidget(table);
    QWidget *test = new QWidget(this);
    test->setLayout(boxLayout);
    //this->setLayout(boxLayout);
    this->setCentralWidget(test);
}

MainWindow::~MainWindow()
{
    delete ui;
}


