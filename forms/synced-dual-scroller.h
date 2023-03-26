//
// Created by mmonfort on 28/02/2023.
//

#ifndef PAPER_MASH_SYNCED_DUAL_SCROLLER_H
#define PAPER_MASH_SYNCED_DUAL_SCROLLER_H

#include <QWidget>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class SyncedDualScroller; }
QT_END_NAMESPACE

class SyncedDualScroller : public QWidget {
Q_OBJECT

public:
    explicit SyncedDualScroller(QWidget *parent = nullptr);

    ~SyncedDualScroller() override;

    void setUpRight(QWidget * widget);
    void setUpLeft(QWidget * widget);
    void setDownRight(QWidget * widget);
    void setDownLeft(QWidget * widget);


private:
    Ui::SyncedDualScroller *ui;
    QWidget * _up_left_widget;
    QWidget * _up_right_widget;
    QWidget * _down_left_widget;
    QWidget * _down_right_widget;


public slots:
    void ScrollbarChanged();



};


#endif //PAPER_MASH_SYNCED_DUAL_SCROLLER_H
