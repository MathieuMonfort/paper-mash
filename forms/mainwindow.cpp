//
// Created by Mathieu Monfort on 26/12/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), _ui(new Ui::MainWindow) {
    _ui->setupUi(this);


}

MainWindow::~MainWindow() {
    delete _ui;
}
