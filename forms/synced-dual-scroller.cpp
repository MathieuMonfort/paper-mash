//
// Created by mmonfort on 28/02/2023.
//

// You may need to build the project (run Qt uic code generator) to get "ui_synced-quad-scroller.h" resolved

#include "synced-dual-scroller.h"
#include "ui_synced-dual-scroller.h"


SyncedDualScroller::SyncedDualScroller(QWidget *parent) :
        QWidget(parent), ui(new Ui::SyncedDualScroller) {
    ui->setupUi(this);
    auto image =new QImage(R"(D:\GRAPH_SPACE\BLENDER\MODELING\Clay Character\RENDER\0001.png)");

    connect(ui->main_horizontal_scrollbar,SIGNAL(valueChanged(int)), this, SLOT(ScrollbarChanged()));
    connect(ui->main_vertical_scrollbar,SIGNAL(valueChanged(int)), this, SLOT(ScrollbarChanged()));


}

SyncedDualScroller::~SyncedDualScroller() {
    delete ui;
}

void SyncedDualScroller::ScrollbarChanged() {
    float hareaFactor = (float)ui->up_right_area->horizontalScrollBar()->maximum() - (float)ui->up_right_area->horizontalScrollBar()->minimum();
    float hmainFactor = (float)ui->main_horizontal_scrollbar->maximum() -(float)ui->main_vertical_scrollbar->minimum();
    float vareaFactor = (float)ui->up_right_area->verticalScrollBar()->maximum() - (float)ui->up_right_area->horizontalScrollBar()->minimum();
    float vmainFactor = (float)ui->main_vertical_scrollbar->maximum() -(float)ui->main_vertical_scrollbar->minimum();

    ui->up_right_area->horizontalScrollBar()->setValue(ui->main_horizontal_scrollbar->value() /  hmainFactor * hareaFactor);
    ui->up_right_area->verticalScrollBar()->setValue(ui->main_vertical_scrollbar->value() / vmainFactor * vareaFactor);

    ui->up_left_area->horizontalScrollBar()->setValue(ui->main_horizontal_scrollbar->value() /  hmainFactor * hareaFactor);
    ui->up_left_area->verticalScrollBar()->setValue(ui->main_vertical_scrollbar->value() / vmainFactor * vareaFactor);

    ui->down_right_area->horizontalScrollBar()->setValue(ui->main_horizontal_scrollbar->value() /  hmainFactor * hareaFactor);
    ui->down_right_area->verticalScrollBar()->setValue(ui->main_vertical_scrollbar->value() / vmainFactor * vareaFactor);

    ui->down_left_area->horizontalScrollBar()->setValue(ui->main_horizontal_scrollbar->value() /  hmainFactor * hareaFactor);
    ui->down_left_area->verticalScrollBar()->setValue(ui->main_vertical_scrollbar->value() / vmainFactor * vareaFactor);

}

void SyncedDualScroller::setUpRight(QWidget *widget) {
    _up_right_widget = widget;
    ui->up_right_area->setWidget(widget);
    ui->up_right_area->setAlignment(Qt::AlignCenter);
}

void SyncedDualScroller::setUpLeft(QWidget *widget) {
    _up_left_widget = widget;
    ui->up_left_area->setWidget(widget);
    ui->up_left_area->setAlignment(Qt::AlignCenter);

}

void SyncedDualScroller::setDownRight(QWidget *widget) {
    _down_right_widget = widget;
    ui->down_right_area->setWidget(widget);
    ui->down_right_area->setAlignment(Qt::AlignCenter);

}

void SyncedDualScroller::setDownLeft(QWidget *widget) {
    _down_left_widget = widget;
    ui->down_left_area->setWidget(widget);
    ui->down_left_area->setAlignment(Qt::AlignCenter);

}

