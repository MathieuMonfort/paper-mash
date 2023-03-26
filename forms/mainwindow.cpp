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
    connect(_ui->input_browse_button, &QPushButton::pressed,this,&MainWindow::BrowseInput);
    connect(_ui->export_button ,&QPushButton::pressed ,this, &MainWindow::RenderMask);
    connect(_ui->generate_grid_button, &QPushButton::pressed, this, &MainWindow::CreateMesh);



    _ui->export_button->setEnabled(false);
    _ui->settings_panel->setEnabled(false);

    _ui->input_path_edit->setText(R"(D:\GRAPH_SPACE\BLENDER\MODELING\Clay Character\RENDER\0001.png)");

    _quad_view = new SyncedDualScroller(nullptr);
    _ui->view_layout->addWidget(_quad_view);

    _ui->zoom_slider->setMinimum(0);
    _ui->zoom_slider->setMaximum(99);

    _ui->zoom_slider->setEnabled(false);
    _quad_view->setEnabled(false);

    connect(_ui->zoom_slider, &QSlider::valueChanged, this, &MainWindow::Zoom);

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

    _width = _inSequence->images->at(0).width();
    _height = _inSequence->images->at(0).height();




    _maskView = new MaskMesh(nullptr);
    _maskView->setFixedSize(_width,_height);

    _wireView = new WireMesh(nullptr);
    _wireView->setFixedSize(_width,_height);

    _imageView = new QLabel(nullptr);
    _imageView->setScaledContents(true);
    _imageView->setPixmap(QPixmap::fromImage(_inSequence->images->at(0)));
    _imageView->setFixedSize(_width,_height);


    _quad_view->setUpRight(_imageView);
    _quad_view->setDownRight(_wireView);
    _quad_view->setDownLeft(_maskView);

    _ui->export_button->setEnabled(true);
    _ui->settings_panel->setEnabled(true);


    _ui->zoom_slider->setEnabled(true);
    _quad_view->setEnabled(true);

}

void MainWindow::BrowseInput() {
    QString filename =  QFileDialog::getOpenFileName(
            this,
            "Select the first image in the sequence",
            QDir::currentPath(),
            "All files (*.*) ;; PNG files (*.png) ;; JPG files (*.jpg);;");
    _ui->input_path_edit->setText(filename);
}

void MainWindow::Zoom() {
    float zoomFactor =((float)_ui->zoom_slider->value() /(float)(_ui->zoom_slider->maximum() - (float) _ui->zoom_slider->minimum() )) *
            (_maxZoomFactor - _minZoomFactor) + _minZoomFactor;

    std::cout << zoomFactor << std::endl;

    _imageView->setFixedSize(_width * zoomFactor,_height * zoomFactor );
    _maskView->setFixedSize(_width * zoomFactor,_height * zoomFactor );
    _wireView->setFixedSize(_width * zoomFactor,_height * zoomFactor );

    _quad_view->ScrollbarChanged();

}

void MainWindow::CreateMesh() {
    Triangle tri1(new Color(1.0f,1.0f,1.0f,1.0f),{
            Point(-0.0f,1.0f),
            Point(0.5f,-0.5f),
            Point(-0.5f,-0.5f)
    });

    _mesh = {tri1};
    _maskView->SetTriangleSet(_mesh);
    _wireView->SetTriangleSet(_mesh);
}
