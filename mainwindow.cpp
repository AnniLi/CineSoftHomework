#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TreeModel.h"
#include "TreeManager.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    std::vector<int> objects = {
        1,
        2,
        3,
        4,
        10,
        11,
        111,
        20,
        31,
        32
    };
    std::vector<QPair<int, int>> objectsDpns = {
        { 1, 11 },
        { 2, 20 },
        { 3, 31 },
        { 3, 32 },
        { 11, 111 }
    };
    auto manager = new TreeManager();
    auto model = new TreeModel(manager);
    manager->addNodes(objects);
    manager->addDependencies(objectsDpns);

    ui->treeView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
