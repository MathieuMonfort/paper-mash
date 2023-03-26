//
// Created by Mathieu Monfort on 26/12/2022.
//

#ifndef PAPER_MASH_MAINWINDOW_H
#define PAPER_MASH_MAINWINDOW_H

#include <iostream>


#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>
#include <mesh.h>
#include <render-window.h>
#include "synced-dual-scroller.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:

    const float _minZoomFactor = 0.1;
    const float _maxZoomFactor = 3;

    int _width, _height;

    Ui::MainWindow *_ui;

    QFileDialog * _inputBrowser;

    MaskMesh * _maskView;
    WireMesh * _wireView;
    QLabel * _imageView;
    TextureRenderWindow * _texRender;

    ImageSequence * _inSequence;
    std::vector<Triangle> _mesh;
    SyncedDualScroller * _quad_view;


public slots:
    void RenderMask();
    void ImportSequence();
    void BrowseInput();
    void CreateMesh();
    void Zoom();

};


#endif //PAPER_MASH_MAINWINDOW_H
