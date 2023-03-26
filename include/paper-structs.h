//
// Created by mmonfort on 29/12/2022.
//

#ifndef PAPER_MASH_PAPER_STRUCTS_H
#define PAPER_MASH_PAPER_STRUCTS_H

#include <vector>

struct Point{
    float x;
    float y;
    Point(float x,float y){
        this->x = x;
        this->y = y;
    }
};

struct Color{
    float * data;
    Color(float r, float g, float b, float a){
        data = new float[4];
        data[0] = r;
        data[1] = g;
        data[2] = b;
        data[3] = a;
    }
};

struct Triangle{
    float * data;
    Color * color;
    Triangle(Color * color, std::vector<Point> points){
        this->color = color;
        data = new float[6];
        for(int i =0 ; i< points.size() ; i++ ){
            *(data + i*2) = points[i].x;
            *(data + i*2 + 1) = points[i].y;
        }
    }
};

struct ImageSequence{
    std::vector<QImage> * images;
    int frames;
    int firstIndex;

    ImageSequence(std::vector<QImage> * images,int firstIndex){
        this->images = images;
        this->firstIndex = firstIndex;
        this->frames = images->size();
    }
};

#endif //PAPER_MASH_PAPER_STRUCTS_H
