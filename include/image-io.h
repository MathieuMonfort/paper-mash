//
// Created by Mathieu Monfort on 29/12/2022.
//

#ifndef PAPER_MASH_IMAGE_IO_H
#define PAPER_MASH_IMAGE_IO_H

#include <QString>
#include <QImage>
#include <QFileInfo>
#include <QDir>
#include <paper-structs.h>


class ImageIO {
public:
    static QImage * LoadImageFromFile(QString path);
    static void SaveImageToFile(QString path, QImage * image);
    static ImageSequence * LoadSequenceFromPattern(QString firstImage);
    static void SaveSequenceToPattern(QString pattern);


private:
    static const QString _numbers;
    static QString getBaseName(QString FullName, int &leadingZeros);

};


#endif //PAPER_MASH_IMAGE_IO_H
