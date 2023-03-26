#include <QApplication>
#include <QMainWindow>
#include "../forms/mainwindow.h"
#include <mesh.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

//    Triangle tri1(new Color(1.0f,1.0f,1.0f,1.0f),{
//            Point(-0.0f,1.0f),
//            Point(0.5f,-0.5f),
//            Point(-0.5f,-0.5f)
//    });
//
//    std::vector<Triangle> _mesh = {tri1};
//
//    QMainWindow * win = new QMainWindow();
//    win->setMinimumSize(720,640);
//    MaskMesh * m = new MaskMesh(nullptr);
//    m->SetTriangleSet(_mesh);
//    win->setCentralWidget(m);
//
//
//    win->show();

    MainWindow window;
    window.show();

    return QApplication::exec();
}
