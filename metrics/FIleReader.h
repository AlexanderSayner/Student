//
// Created by alexa on 5/31/2020.
//

#ifndef METRICS_FILEREADER_H
#define METRICS_FILEREADER_H

#include "flower.h"
#include <fstream>

class FIleReader {
public:
    int clearOrCreateFile(const char *fileName);

    int writeIntoNewFile(const char *fileName, const Flower &flower);

    char *readFromTheFile(const char *fileName);
};


#endif //METRICS_FILEREADER_H
