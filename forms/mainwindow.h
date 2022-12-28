//
// Created by Mathieu Monfort on 26/12/2022.
//

#ifndef PAPER_MASH_MAINWINDOW_H
#define PAPER_MASH_MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "../include/mesh.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private:

    void InitializeView(){

    }

    Ui::MainWindow *_ui;
};


#endif //PAPER_MASH_MAINWINDOW_H
