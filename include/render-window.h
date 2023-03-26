//
// Created by mmonfort on 29/12/2022.
//

#ifndef PAPER_MASH_RENDER_WINDOW_H
#define PAPER_MASH_RENDER_WINDOW_H

#include <iostream>
#include <vector>

#include <QOpenGLWindow>
#include <QOpenGLShaderProgram>
#include <QOpenGLContext>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>

#include <paper-structs.h>
#include <image-io.h>


class RenderWindow : public QOpenGLWindow{
    Q_OBJECT
public:
    RenderWindow(QWindow * parent,ImageSequence * sequence) : QOpenGLWindow(NoPartialUpdate, parent){
        this->_sequence = sequence;
    }

    void SetTriangleSet(std::vector<Triangle> triangles);
    void initializeGL() override;
    void paintGL() override;

    void RenderFrame(int frame, QString path);
protected:
    QOpenGLShaderProgram * _shader;
    std::vector<Triangle> _mesh;
    ImageSequence * _sequence;

    GLint _posAttr;
    GLint _texAttr;
private:
    virtual void InitializeGlShaders(){};
    virtual void PaintSetup(){};


    void DrawTriangle(Triangle tri);
};


class MaskRenderWindow : public RenderWindow{
public:
    MaskRenderWindow(QWindow * parent, ImageSequence * sequence) : RenderWindow(parent,sequence){}
private:
    void InitializeGlShaders() override;
    void PaintSetup() override;
};

class TextureRenderWindow : public RenderWindow{
public:
    TextureRenderWindow(QWindow * parent, ImageSequence * sequence) : RenderWindow(parent,sequence){

    }

private:
    QOpenGLTexture * _tex;

    void InitializeGlShaders() override;
    void PaintSetup() override;
};

#endif //PAPER_MASH_RENDER_WINDOW_H
