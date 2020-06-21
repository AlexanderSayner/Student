//
// Created by alexa on 6/18/2020.
//

#include "DataService.h"

std::string DataService::search(char *data, const std::string search) {
    auto *buffer = new std::string("");
    bool *isFound = new bool(false);

    for (char *it = data; *it; ++it) {
        auto *buf = new std::string(*buffer + *it);
        delete buffer;
        buffer = new std::string(*buf);
        delete buf;

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
    return 0;
    return 0;
}

std::string DataService::searchByColor(const std::string &data, const std::string &search) {
    bool isFound = false;
    int flag = 1, counter = 0;
    std::string buffer, record;
    for (auto it : data) {
        if (isFound && it == '|') {
            return record;
        }
        if (it == '|') {
            record = "";
            counter = 0;
            buffer = "";
        }
        if (it != '_') {
            record += it;
        } else {
            record += ' ';
        }
        if (it == '_') {
            counter++;
        }
        if (!isFound && counter < flag) {
            continue;
        }
        if (!isFound && counter == flag) {
            if (it != '_') {
                buffer += it;
            }
        }
        if (!isFound && counter > flag) {
            size_t pos = buffer.find(search);
            if (pos != std::string::npos) {
                isFound = true;
            }
        }
    }
    return std::__cxx11::string();
}

std::string DataService::searchByLetter(const std::string &data, const std::string &search) {
    bool isFound = false;
    int flag = 2, counter = 0;
    std::string buffer, record;

    for (auto it : data) {
        if (isFound && it == '|') {
            return record;
        }
        if (!isFound && counter > flag) {
            if (buffer == search)
                isFound = true;
        }
        if (it == '|') {
            record = "";
            counter = 0;
            buffer = "";
        }
        if (it != '_') {
            record += it;
        } else {
            record += ' ';
        }
        if (it == '_') {
            counter++;
        }
        if (!isFound && counter < flag) {
            continue;
        }
        if (!isFound && counter == flag) {
            if (it != '_') {
                buffer += it;
            }
        }
    }
    return std::__cxx11::string();
}

std::string DataService::searchByRange(const std::string &data, int start, int end, int flag) {
    bool isFound = false;
    int counter = 0;
    std::string buffer, record;

    for (auto it : data) {
        if (isFound && it == '|') {
            return record;
        }
        if (it == '|') {
            record = "";
            counter = 0;
            buffer = "";
        }
        if (it != '_') {
            record += it;
        } else {
            record += ' ';
        }
        if (it == '_') {
            counter++;
        }
        if (!isFound && counter < flag) {
            continue;
        }
        if (!isFound && counter == flag) {
            if (it != '_') {
                buffer += it;
            }
        }
        if (it == '|' || !isFound && counter > flag) {
            if (std::stoi(buffer) >= start && std::stoi(buffer) <= end)
                isFound = true;
        }
    }
    return std::__cxx11::string();
}
