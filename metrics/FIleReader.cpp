//
// Created by alexa on 5/31/2020.
//

#include "FIleReader.h"

int FIleReader::clearOrCreateFile(const char *fileName) {
    std::ofstream outfile(fileName);
    if (!outfile) {
        std::cout << "Can't create file " << fileName;
        return -1;
    }
    outfile.close();
    return 0;
}

int FIleReader::writeIntoNewFile(const char *fileName, const Flower &flower) {
    std::ofstream outfile(fileName, std::ios::in | std::ios::app);
    if (!outfile) {
        std::cout << "Can't open file " << fileName;
        return -1;
    }
    std::string buffer = flower.name;
    buffer += '_';
    buffer += flower.color;
    buffer += '_';
    buffer += flower.isBlossom;
    buffer += '|';
    outfile << buffer << '\n';
    outfile.close();
    return 0;
}

char *FIleReader::readFromTheFile(const char *fileName) {
    auto *infile = new std::ifstream(fileName, std::ios::binary);
    if (!infile->is_open()) {
        std::cout << "Can't read file " << fileName;
        return nullptr;
    }
    infile->seekg(0, std::ios::end);
    int n = infile->tellg();
    infile->seekg(0, std::ios::beg);
    char *s = new char[n + 1];
    s[n] = 0;
    infile->read(s, n);
    infile->close();
    free(infile);
    return s;
}
