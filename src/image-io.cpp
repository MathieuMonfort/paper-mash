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

ImageSequence *ImageIO::LoadSequenceFromPattern(QString firstImagePath) {
    std::vector<QImage> * images = new std::vector<QImage>;
    QImage * firstImage = new QImage(firstImagePath);
    if(firstImage->isNull()){
        return nullptr;
    }

    QFileInfo first(firstImagePath);

    int leadingZeros;
    int firstIndex;
    QString ext = first.suffix();
    QString baseName = getBaseName(first.baseName(),firstIndex,leadingZeros);
    QString directory = first.absolutePath();

    QImage * current;

    int index = firstIndex+1;
    do{
        std::ostringstream pathStream;
        pathStream << directory.toStdString() << "/" << baseName.toStdString() << std::setfill('0') << std::setw(leadingZeros) << index << "." << ext.toStdString();
        auto path = pathStream.str();
        current = new QImage(path.c_str());
        index++;
        if(!current->isNull()){
            images->push_back(*current);
        }
    }while(!current->isNull());
    return new ImageSequence(images, firstIndex);
}

void ImageIO::SaveSequenceToPattern(QString pattern) {

}

QString ImageIO::getBaseName(QString FullName,int &firstIndex, int &leadingZeros) {
    leadingZeros =0;
    int baseCharacterNumbers = 0;
    QString res = "";
    firstIndex = 0;


    for(int i = FullName.length() -1 ;i>= 0 ;i--){
        if(_numbers.contains(FullName[i]) ){
            firstIndex += ((int)FullName[i].unicode() - '0')* std::pow(10,FullName.length() -1 -i);
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
