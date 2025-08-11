#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>
#include <QColor>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("background-color: lightblue;");

    //list of buttons
    QPushButton* buttons[] = {
        ui->pushButton_A, ui->pushButton_B, ui->pushButton_C, ui->pushButton_D,
        ui->pushButton_E, ui->pushButton_F, ui->pushButton_g, ui->pushButton_H,
        ui->pushButton_I, ui->pushButton_J, ui->pushButton_K, ui->pushButton_L,
        ui->pushButton_M, ui->pushButton_N, ui->pushButton_enne, ui->pushButton_O,
        ui->pushButton_P, ui->pushButton_Q, ui->pushButton_R, ui->pushButton_S,
        ui->pushButton_T, ui->pushButton_U, ui->pushButton_V, ui->pushButton_W,
        ui->pushButton_X, ui->pushButton_Y, ui->pushButton_Z
    };

    //unique style for each one
    QString button_style = "background-color: #2F4F4F; color: white;";
    //to change all the buttons
    for (QPushButton* btn : buttons) {
        if (btn) btn->setStyleSheet(button_style);
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}
