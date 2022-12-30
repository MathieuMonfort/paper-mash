//
// Created by mmonfort on 29/12/2022.
//

#include "image-io.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image_write.h"

unsigned char *ImageIO::GetDataFromFile(QString path, int &width, int &height, int &channels) {
    /*unsigned char *data = stbi_load(path.toStdString().c_str(), &width, &height,&channels,0);

    if(data == nullptr){
        width = 0;
        height = 0;
        channels = 0;
    }

    return data;*/
    return nullptr;
}

void ImageIO::writeDataToFile(QString path, int width, int height, int channels, unsigned char *data) {
    //stbi_write_png(path.toStdString().c_str(), width,height, channels,data,width* sizeof(unsigned char) * channels);
}
