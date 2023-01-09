//
// Created by mmonfort on 29/12/2022.
//

#include "image-io.h"

const QString ImageIO::_numbers = "0123456789";


QImage * ImageIO::LoadImageFromFile(QString path) {
    QImage * res = new QImage(path);
    return res;
}

void ImageIO::SaveImageToFile(QString path, QImage * image) {
    image->save(path);
}

ImageSequence *ImageIO::LoadSequenceFromPattern(QString firstImage) {

    QFileInfo first(firstImage);
    QString ext = first.suffix();
    int leadingZeros;
    QString baseName = getBaseName(first.baseName(),leadingZeros);
    QString directory = first.absolutePath();



    std::vector<QImage> * images;
    ImageSequence * res = new ImageSequence(images);
    return nullptr;
}

void ImageIO::SaveSequenceToPattern(QString pattern) {

}

QString ImageIO::getBaseName(QString FullName, int &leadingZeros) {
    leadingZeros =0;
    int baseCharacterNumbers = 0;
    QString res = "";

    for(int i = FullName.length() -1 ;i>= 0 ;i--){
        if(_numbers.contains(FullName[i]) ){
            leadingZeros ++;
        }
        else{
            baseCharacterNumbers = i+1;
            break;
        }
    }

    for(int i = 0; i < baseCharacterNumbers; i++ ){
        res += FullName[i];
    }

    return res;
}
