#include <iostream>

int fun2(){
    std::string s = "Rose_Red_y_13_40_|\n"
                    "Cactus_Green_n_15_25_|";

    bool isFound = false;
    int flag = 5, counter = 0;
    std::string buffer, record;

    int start = 0, end = 10000;

    for (auto it : s) {
        if (isFound && it == '|') {
            std::cout << "FUCK  " << record << "\n";
            return 0;
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
        if (it=='|' || it == '_') {
            counter++;
        }
        if (!isFound && counter < flag) {
            continue;
        }
        if (!isFound && counter == flag) {
            if (it != '_') {
                buffer += it;
            }
            std::cout << "FUCK FUCK FUCK " << buffer << "\n";
        }
        if (!isFound && counter > flag) {
            std::cout << "Fucking shit " << buffer << "\n";
            if (std::stoi(buffer) >= start && std::stoi(buffer) <= end)
                isFound = true;
        }
    }
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
}

int fun() {
    std::string s = "Rose_Red_y_13_40|\n"
                    "Cactus_Green_n_15_25|";

    bool isFound = false;
    int flag = 1, counter = 0;
    std::string buffer, record;
    for (auto it : s) {
        if (isFound && it == '|') {
            std::cout << "FUCK  " << record << "\n";
            return 0;
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
            std::cout << "FUCK FUCK FUCK " << buffer << "\n";
        }
        if (!isFound && counter > flag) {
            size_t pos = buffer.find("ee");
            if (pos != std::string::npos) {
                std::cout << "Found at pos = " << pos << "\n";
                isFound = true;
            } else
                std::cout << "Not found\n";
        }
    }
    return 0;
}
int gun(){

    std::string s = "Rose_Red_y_13_40|\n"
                    "Cactus_Green_n_15_25|";

    bool isFound = false;
    int flag = 2, counter = 0;
    std::string buffer, record;

    for (auto it : s) {
        if (isFound && it == '|') {
            std::cout << "FUCK  " << record << "\n";
            return 0;
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
            std::cout << "FUCK FUCK FUCK " << buffer << "\n";
        }
        if (!isFound && counter > flag) {
            std::cout << "Fucking shit " << buffer << "\n";
            if (buffer=="n")
                isFound = true;
        }
    }
    return 0;
}

int main() {
    fun2();
    return 0;
}
