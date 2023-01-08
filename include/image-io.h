//
// Created by Mathieu Monfort on 29/12/2022.
//

#ifndef PAPER_MASH_IMAGE_IO_H
#define PAPER_MASH_IMAGE_IO_H

#include <QString>
#include <QImage>
#include <paper-structs.h>


class ImageIO {
public:
    static QImage * LoadImageFromFile(QString path);
    static void SaveImageToFile(QString path, QImage * image);
    static ImageSequence * LoadSequenceFromPattern(QString pattern);
    static void SaveSequenceToPattern(QString pattern);


private:
};

class LoadException : public std::exception{
public:
    explicit LoadException(const std::string& message) :msg_(message){}

    virtual ~LoadException() noexcept {}

    virtual const char * what() const noexcept{
        return msg_.c_str();
    }

public:
    explicit LoadException(const char * message) :msg_(message){}

protected:
    std::string msg_;
};


#endif //PAPER_MASH_IMAGE_IO_H
