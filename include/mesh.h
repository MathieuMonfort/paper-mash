//
// Created by Mathieu Monfort on 28/12/2022.
//

#ifndef PAPER_MASH_MESH_H
#define PAPER_MASH_MESH_H

#include <vector>


#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>

#include <paper-structs.h>

class Mesh : public QOpenGLWidget{
public:
    explicit Mesh(QWidget * parent);

    void SetTriangleSet(std::vector<Triangle> triangles);
    void initializeGL() override;
    void paintGL() override;

private:

    void InitializeGlShaders();

    std::vector<Triangle> _triangles;
    GLuint _posAttr;
    GLuint _texAttr;

    QOpenGLShaderProgram * _shader;
    virtual void PaintSetup(){};
    void DrawTriangle(Triangle tri);

};

class WireMesh : public Mesh{
public:
    explicit WireMesh(QWidget * parent): Mesh(parent){}
private:
    void PaintSetup() override;
};

class MaskMesh : public Mesh{
public:
    explicit MaskMesh(QWidget * parent): Mesh(parent){}
private:
    void PaintSetup() override;

};





#endif //PAPER_MASH_MESH_H
