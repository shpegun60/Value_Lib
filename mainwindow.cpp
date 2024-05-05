#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "value_base.h"
#include "array_value_base.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ValueBase<uint32_t> desc1;
    ValueBase<float> desc2;
    ArrayValueBase<uint32_t, 5> arr;

    std::cout << "desc1 type: " << static_cast<int>(desc1.getType()) << std::endl;
    std::cout << "desc2 type: " << static_cast<int>(desc2.getType()) << std::endl;
    std::cout << "sizeof: " << sizeof(desc2) << std::endl;

    //desc2.setValue(6);
    std::cout << "desc2 val: " << desc2.getValue();
    //desc2.
    //arr.
}

MainWindow::~MainWindow()
{
    delete ui;
}
