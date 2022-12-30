//
// Created by mmonfort on 29/12/2022.
//

#ifndef PAPER_MASH_IMAGE_IO_H
#define PAPER_MASH_IMAGE_IO_H

#include <QString>

class ImageIO {
public:
    static unsigned char * GetDataFromFile(QString path, int &width, int &height, int &channels);
    static void writeDataToFile(QString path,int width, int height, int channels, unsigned char* data);

};


#endif //PAPER_MASH_IMAGE_IO_H
