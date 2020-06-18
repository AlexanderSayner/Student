//
// Created by alexa on 6/18/2020.
//

#ifndef THIRD_FILEREADER_H
#define THIRD_FILEREADER_H

#include "flower.h"
#include <fstream>

class FIleReader {
public:
    int clearOrCreateFile(const char *fileName);

    int writeIntoNewFile(const char *fileName, const Flower &flower);

    char *readFromTheFile(const char *fileName);
};


#endif //THIRD_FILEREADER_H
