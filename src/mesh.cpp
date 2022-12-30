//
// Created by Mathieu Monfort on 28/12/2022.
//

#include "../include/mesh.h"
Mesh::Mesh(QWidget *parent)  : QOpenGLWidget(parent){
}

void Mesh::SetTriangleSet(std::vector<Triangle> triangles) {
    this->_triangles = triangles;
}

void Mesh::initializeGL() {
    InitializeGlShaders();
}

void Mesh::paintGL() {
    context()->functions()->glClearColor(0.0,0.0,0.0,1.0);

    PaintSetup();
    _shader->bind();
    for(auto t : _triangles){
        DrawTriangle(t);
    }

    _shader->release();
}

void Mesh::InitializeGlShaders() {
    _shader = new QOpenGLShaderProgram(nullptr);
    _shader->addShaderFromSourceFile(QOpenGLShader::Vertex,"resources/color.vert");
    _shader->addShaderFromSourceFile(QOpenGLShader::Fragment,"resources/color.frag");

    _shader->bindAttributeLocation("aPos",0);
    _shader->bindAttributeLocation("aTex",1);
    _shader->link();

//    _posAttr = _shader->attributeLocation("apos");
//    Q_ASSERT(_posAttr != -1);
//    _texAttr = _shader->attributeLocation("atex");
//    Q_ASSERT(_texAttr != -1);


}

void Mesh::DrawTriangle(Triangle tri) {
    context()->functions()->glVertexAttribPointer(_posAttr,2,GL_FLOAT, GL_FALSE,0,tri.data);
    context()->functions()->glVertexAttribPointer(_texAttr,2,GL_FLOAT, GL_FALSE,0,tri.data);

    context()->functions()->glEnableVertexAttribArray(_posAttr);
    context()->functions()->glEnableVertexAttribArray(_texAttr);

    context()->functions()->glDrawArrays(GL_TRIANGLES,0,3);

    context()->functions()->glDisableVertexAttribArray(_texAttr);
    context()->functions()->glDisableVertexAttribArray(_posAttr);
}

void WireMesh::PaintSetup() {
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

void MaskMesh::PaintSetup() {
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
}


