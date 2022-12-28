//
// Created by Mathieu Monfort on 28/12/2022.
//

#ifndef PAPER_MASH_MESH_H
#define PAPER_MASH_MESH_H

#include <vector>
using namespace std;


#include <QOpenGLShaderProgram>
#include <QOpenGLWidget>
#include <QOpenGLContext>
#include <QOpenGLFunctions>


struct Point;
struct Triangle;

class Mesh : public QOpenGLWidget{
public:

private:
    vector<Triangle> * _triangles;


};

class WireMesh : public Mesh{

};

class MaskMesh : public Mesh{

};



struct Point{
    float x;
    float y;
    Point(float x,float y){
        this->x = x;
        this->y = y;
    }
};

struct Color{
    float r;
    float g;
    float b;
    float a;
    Color(float r, float g, float b, float a){
        this->r = r;
        this->g = g;
        this->b = b;
        this->a = a;
    }
};

struct Triangle{
    float * data;
    Color * color;
    Triangle(Color * color, vector<Point> points){
        this->color = color;
        data = new float[6];
        for(int i =0 ; i< points.size() ; i++ ){
            *(data + i*2) = points[i].x;
            *(data + i*2 + 1) = points[i].y;
        }
    }
};


#endif //PAPER_MASH_MESH_H
