//
// Created by Mathieu Monfort on 26/12/2022.
//

#ifndef PAPER_MASH_MAINWINDOW_H
#define PAPER_MASH_MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <mesh.h>
#include <render-window.h>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:

    Ui::MainWindow *_ui;

    MaskMesh * _maskView;
    WireMesh * _wireView;
    TextureRenderWindow * _texRender;

    ImageSequence * _inSequence;
    std::vector<Triangle> _mesh;

public slots:
    void RenderMask();
    void ImportSequence();


};


#endif //PAPER_MASH_MAINWINDOW_H
