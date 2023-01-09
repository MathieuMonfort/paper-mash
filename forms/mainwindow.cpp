//
// Created by Mathieu Monfort on 26/12/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), _ui(new Ui::MainWindow) {
    _ui->setupUi(this);



    connect(_ui->import_button,&QPushButton::pressed, this, &MainWindow::ImportSequence);
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::RenderMask() {
    auto seq =  ImageIO::LoadSequenceFromPattern("C:/images/img_#####");

    _texRender = new TextureRenderWindow(nullptr,seq);
    _texRender->SetTriangleSet(_mesh);
    _texRender->show();

}

void MainWindow::ImportSequence() {
    
        _inSequence = ImageIO::LoadSequenceFromPattern(_ui->input_path_edit->text());
        if(!_inSequence){
            QMessageBox mb(nullptr);
            mb.setText("Sequence could not be loaded");
            mb.exec();
            return;
        }

    _maskView = new MaskMesh(this);
    _wireView = new WireMesh(this);

    _maskView->setFixedSize(1920/4,1080/4);
    _wireView->setFixedSize(1920/4,1080/4);

    Triangle tri1(new Color(1.0f,1.0f,1.0f,1.0f),{
            Point(-0.0f,1.0f),
            Point(0.5f,-0.5f),
            Point(-0.5f,-0.5f)
    }) ;

    _mesh = {tri1};

    _maskView->SetTriangleSet(_mesh);
    _wireView->SetTriangleSet(_mesh);
    _ui->up_view_panel->layout()->addWidget(_maskView);
    _ui->down_view_panel->layout()->addWidget(_wireView);

    connect(_ui->export_button ,&QPushButton::pressed ,this, &MainWindow::RenderMask);

}
