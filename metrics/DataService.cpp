//
// Created by alexa on 5/31/2020.
//

#include "DataService.h"

std::string DataService::search(char *data, const std::string &search) {
    auto* buffer=new std::string("");
    bool *isFound = new bool(false);

    for (char *it = data; *it; ++it) {
        auto *buf = new std::string(*buffer + *it);
        delete buffer;
        buffer = new std::string(*buf);

        if (*buffer == search && !*isFound) {
            *isFound = true;
        }
        if (*isFound && (*it == '|' || *it == '\n')) {
            std::cout << "Got it:\n" << *buffer << '\n';
            return *buffer;
        }

        if (*it == '|' || *it == '\n') {
            delete buffer;
            buffer = new std::string("");
        }
    }
    return std::__cxx11::string();
}
