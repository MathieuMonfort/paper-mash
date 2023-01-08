//
// Created by mmonfort on 29/12/2022.
//

#include "image-io.h"

QImage * ImageIO::LoadImageFromFile(QString path) {
    QImage * res = new QImage(path);
    return res;
}

void ImageIO::SaveImageToFile(QString path, QImage * image) {
    image->save(path);
}

ImageSequence *ImageIO::LoadSequenceFromPattern(QString pattern) {
    std::vector<QImage> * images;
    ImageSequence * res = new ImageSequence(images);
    return nullptr;
}

void ImageIO::SaveSequenceToPattern(QString pattern) {

}
