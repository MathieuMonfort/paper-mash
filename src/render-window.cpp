//
// Created by mmonfort on 29/12/2022.
//

#include "render-window.h"

void RenderWindow::SetTriangleSet(std::vector<Triangle> triangles) {
    this->_mesh = triangles;
}

void RenderWindow::initializeGL() {
    InitializeGlShaders();
}

void RenderWindow::paintGL() {

    PaintSetup();
    _shader->bind();

    for(auto t : _mesh){
        DrawTriangle(t);
    }

    _shader->release();
}


void RenderWindow::DrawTriangle(Triangle tri) {
    context()->functions()->glVertexAttribPointer(_posAttr,2,GL_FLOAT, GL_FALSE,0,tri.data);
    context()->functions()->glVertexAttribPointer(_texAttr,2,GL_FLOAT, GL_FALSE,0,tri.data);

    context()->functions()->glEnableVertexAttribArray(_posAttr);
    context()->functions()->glEnableVertexAttribArray(_texAttr);

    context()->functions()->glDrawArrays(GL_TRIANGLES,0,3);

    context()->functions()->glDisableVertexAttribArray(_texAttr);
    context()->functions()->glDisableVertexAttribArray(_posAttr);
}

void RenderWindow::RenderFrame(int frame, QString path) {
    unsigned char * data = new unsigned char[this->width() * this->height() * 4];
    glReadPixels(0,0,this->width(),this->height(), GL_RGBA, GL_UNSIGNED_BYTE ,data);
    QImage * img = new QImage();
    ImageIO::SaveImageToFile(path,img);
}

void MaskRenderWindow::InitializeGlShaders() {
    _shader = new QOpenGLShaderProgram(nullptr);
    _shader->addShaderFromSourceFile(QOpenGLShader::Vertex,"resources/mask.vert");
    _shader->addShaderFromSourceFile(QOpenGLShader::Fragment,"resources/mask.frag");


    _shader->bindAttributeLocation("aPos",0);
    _shader->bindAttributeLocation("aTex",1);



    _posAttr = 0;
    _texAttr = 1;
    _shader->link();


}

void MaskRenderWindow::PaintSetup() {
    glClearColor(0.0,0.0,0.0,1.0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}

void TextureRenderWindow::InitializeGlShaders() {
    _shader = new QOpenGLShaderProgram(nullptr);
    _shader->addShaderFromSourceFile(QOpenGLShader::Vertex,"resources/texture.vert");
    _shader->addShaderFromSourceFile(QOpenGLShader::Fragment,"resources/texture.frag");

    _shader->bindAttributeLocation("aPos",0);
    _shader->bindAttributeLocation("aTex",1);

    _posAttr = 0;
    _texAttr = 1;

    _shader->link();
    _shader->setUniformValue("texture",0);
}

void TextureRenderWindow::PaintSetup() {
    glClearColor(0.0,0.0,0.0,0.0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}
