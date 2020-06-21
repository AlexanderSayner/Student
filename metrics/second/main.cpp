#include <iostream>
#include <fstream>

using namespace std;

struct Flower {
    std::string name;
    std::string color;
    char isBlossom;
    int number;
    int height;
};

int main() {
    std::string yourChose;
    while (true) {
        std::cout << "Welcome to the Epic Intellij Awesome Menu" << '\n';
        std::cout << "Type that do you want" << '\n';
        std::string one = "1 I want to add some record";
        std::string two = "2 I want to see all records";
        std::string three = "3 I want to search for some record";
        std::string exit = "0 I don't want to press ctrl^C, but go out";
        std::cout << one << '\n';
        std::cout << two << '\n';
        std::cout << three << '\n';
        std::cout << exit << '\n';
        yourChose = "";
        std::cin >> yourChose;
        const char *fileName = "database.txt";
        if (yourChose == one || yourChose == "1") {

            int mode;
            std::cout << "1 - auto mode, 0 - manual\n";
            std::cin >> mode;

            if (mode == 1) {
                std::cout << "Welcome to Intellij Add" << '\n';
                auto *outfile1 = new ofstream();
                outfile1->open(fileName);
                if (!*outfile1) {
                    cout << "Can't create file " << *fileName;
                    return -1;
                }
                outfile1->close();
                Flower *rose = new Flower();
                rose->name = "Rose";
                rose->color = "Red";
                rose->isBlossom = 'y';
                rose->number = 13;
                rose->height = 40;
                Flower *cactus = new Flower();
                cactus->name = "Cactus";
                cactus->color = "Green";
                cactus->isBlossom = 'n';
                cactus->number = 15;
                cactus->height = 25;
                auto *outfile = new ofstream();
                outfile->open(fileName, std::ios::in | std::ios::app);
                if (!*outfile) {
                    cout << "Can't create file " << *fileName;
                    return -1;
                }
                std::string *buffer = new string();
                *buffer += rose->name;
                *buffer += '_';
                *buffer += rose->color;
                *buffer += '_';
                *buffer += rose->isBlossom;
                *buffer += '_';
                *buffer += std::to_string(rose->number);
                *buffer += '_';
                *buffer += std::to_string(rose->height);
                *buffer += '_';
                *buffer += '|';
                *outfile << *buffer << '\n';
                *buffer = cactus->name;
                *buffer += '_';
                *buffer += cactus->color;
                *buffer += '_';
                *buffer += cactus->isBlossom;
                *buffer += '_';
                *buffer += std::to_string(cactus->number);
                *buffer += '_';
                *buffer += std::to_string(cactus->height);
                *buffer += '_';
                *buffer += '|';
                *outfile << *buffer << '\n';
                outfile->close();
            } else {
                auto *outfile1 = new ofstream();
                outfile1->open(fileName);
                if (!*outfile1) {
                    cout << "Can't create file " << *fileName;
                    return -1;
                }
                outfile1->close();
                free(outfile1);
                bool *isOneMore = new bool(true);
                while (*isOneMore) {
                    auto *flower = new Flower();
                    std::cout << "Flower Name, please:" << '\n';
                    std::cin >> flower->name;
                    std::cout << "Flower color is:" << '\n';
                    std::cin >> flower->color;
                    std::cout << "Is it blossom? y/n" << '\n';
                    std::cin >> flower->isBlossom;
                    std::cout << "How many flowers?" << '\n';
                    std::cin >> flower->number;
                    std::cout << "Flower height" << '\n';
                    std::cin >> flower->height;
                    auto *outfile = new ofstream();
                    outfile->open(fileName, std::ios::in | std::ios::app);
                    if (!*outfile) {
                        cout << "Can't create file " << *fileName;
                        return -1;
                    }
                    std::string *buffer = new string();
                    *buffer += flower->name;
                    *buffer += '_';
                    *buffer += flower->color;
                    *buffer += '_';
                    *buffer += flower->isBlossom;
                    *buffer += '_';
                    *buffer += std::to_string(flower->number);
                    *buffer += '_';
                    *buffer += std::to_string(flower->height);
                    *buffer += '_';
                    *buffer += '|';
                    *outfile << *buffer << '\n';
                    std::cout << "Do you want write one more? Y/n";
                    char *answer;
                    std::cin >> *answer;
                    switch (*answer) {
                        case 'Y':
                        case 'y': {
                            *isOneMore = true;
                            break;
                        }
                        default:
                            *isOneMore = false;
                            break;
                    }
                    outfile->close();
                    free(outfile);
                }
            }
        }
        if (yourChose == two || yourChose == "2") {
            auto *infile = new std::ifstream(fileName, std::ios::binary);
            if (!infile->is_open()) {
                std::cout << "Can't read file " << fileName;
                return 1;
            }
            infile->seekg(0, std::ios::end);
            int n = infile->tellg();
            infile->seekg(0, std::ios::beg);
            char *s = new char[n + 1];
            s[n] = 0;
            infile->read(s, n);
            infile->close();
            free(infile);
            std::cout << "There are file records:\n" << s << '\n';
        }
        if (yourChose == three || yourChose == "3") {
            std::cout << "Welcome to Intellij Search" << '\n';
            std::cout << "What do you want search for? Type it below." << '\n';
            std::string name = "Name, please - 0";
            std::string color = "Color, please - 1";
            std::string letter = "Letter, please - 2";
            std::string count = "Count, please - 3";
            std::string height = "Height, please - 4";
            std::string exit1 = "To the Intellij Menu, please - 5";
            yourChose = "";
            std::cin >> yourChose;
            if (yourChose == name || yourChose == "0") {
                yourChose = "";
                auto *infile = new std::ifstream(fileName, std::ios::binary);
                if (!infile->is_open()) {
                    std::cout << "Can't read file " << fileName;
                    return 1;
                }
                infile->seekg(0, std::ios::end);
                int n = infile->tellg();
                infile->seekg(0, std::ios::beg);
                char *data = new char[n + 1];
                data[n] = 0;
                infile->read(data, n);
                infile->close();
                free(infile);
                std::cout << "Searching by name\n" << "Please, enter the flowers name:\n";
                std::string inputSearch;
                std::cin >> inputSearch;
                string *buffer = new string();
                bool *isFound = new bool(false);

                for (char *it = data; *it; ++it) {
                    *buffer += *it;

                    if (*buffer == inputSearch && !*isFound) {
                        *isFound = true;
                    }
                    if (*isFound && (*it == '|' || *it == '\n')) {
                        std::cout << "Got it:\n" << *buffer << '\n';
                        break;
                    }

                    if (*it == '|' || *it == '\n') {
                        *buffer = "";
                    }
                }
            } else if (yourChose == color || yourChose == "1") {
                auto *infile = new std::ifstream(fileName, std::ios::binary);
                if (!infile->is_open()) {
                    std::cout << "Can't read file " << fileName;
                    return 1;
                }
                infile->seekg(0, std::ios::end);
                int n = infile->tellg();
                infile->seekg(0, std::ios::beg);
                char *data = new char[n + 1];
                data[n] = 0;
                infile->read(data, n);
                infile->close();
                free(infile);
                std::cout << "Tell me your color" << '\n';
                std::string inputSearch;
                std::cin >> inputSearch;
                bool isFound = false;
                int flag = 2, counter = 0;
                std::string buffer, record;

                for (int i = 0; i < n + 1; i++) {
                    char it = data[i];
                    if (isFound && it == '|') {
                        std::cout << record << '\n';
                        break;
                    }
                    if (!isFound && counter > flag) {
                        if (buffer == inputSearch)
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
            } else if (yourChose == letter || yourChose == "2") {
                auto *infile = new std::ifstream(fileName, std::ios::binary);
                if (!infile->is_open()) {
                    std::cout << "Can't read file " << fileName;
                    return 1;
                }
                infile->seekg(0, std::ios::end);
                int n = infile->tellg();
                infile->seekg(0, std::ios::beg);
                char *data = new char[n + 1];
                data[n] = 0;
                infile->read(data, n);
                infile->close();
                free(infile);
                std::cout << "Tell me yes or no" << '\n';
                std::string inputSearch;
                std::cin >> inputSearch;
                bool *isFound = new bool(false);
                int flag = 2, counter = 0;
                std::string *buffer = new string(), *record = new string();

                for (char *it = data; *it; ++it) {
                    if (*isFound && *it == '|') {
                        std::cout << record << '\n';
                        break;
                    }
                    if (!*isFound && counter > flag) {
                        if (*buffer == inputSearch)
                            *isFound = true;
                    }
                    if (*it == '|') {
                        *record = "";
                        counter = 0;
                        *buffer = "";
                    }
                    if (*it != '_') {
                        *record += *it;
                    } else {
                        *record += ' ';
                    }
                    if (*it == '_') {
                        counter++;
                    }
                    if (!*isFound && counter < flag) {
                        continue;
                    }
                    if (!*isFound && counter == flag) {
                        if (*it != '_') {
                            *buffer += *it;
                        }
                    }
                }
            } else if (yourChose == count || yourChose == "3") {
                auto *infile = new std::ifstream(fileName, std::ios::binary);
                if (!infile->is_open()) {
                    std::cout << "Can't read file " << fileName;
                    return 1;
                }
                infile->seekg(0, std::ios::end);
                int n = infile->tellg();
                infile->seekg(0, std::ios::beg);
                char *data = new char[n + 1];
                data[n] = 0;
                infile->read(data, n);
                infile->close();
                free(infile);
                std::cout << "Searching by name\n" << "Please, enter the flowers name:\n";
                std::string inputSearch;
                std::cin >> inputSearch;
                bool isFound = false;
                int flag = 3, counter = 0;
                std::string *buffer = new string(), *record = new string();
                std::cout << "Write two numbers for count" << '\n';
                std::cout << "One" << '\n';
                int start;
                std::cin >> start;
                std::cout << "Two" << '\n';
                int end;
                std::cin >> end;

                for (char *it = data; *it; ++it) {
                    if (isFound && *it == '|') {
                        std::cout << record << '\n';
                        break;
                    }
                    if (*it == '|') {
                        *record = "";
                        counter = 0;
                        *buffer = "";
                    }
                    if (*it != '_') {
                        *record += it;
                    } else {
                        *record += ' ';
                    }
                    if (*it == '_') {
                        counter++;
                    }
                    if (!isFound && counter < flag) {
                        continue;
                    }
                    if (!isFound && counter == flag) {
                        if (*it != '_') {
                            *buffer += it;
                        }
                    }
                    if (*it == '|' || !isFound && counter > flag) {
                        if (std::stoi(*buffer) >= start && std::stoi(*buffer) <= end)
                            isFound = true;
                    }
                }
            } else if (yourChose == height || yourChose == "4") {
                auto *infile = new std::ifstream(fileName, std::ios::binary);
                if (!infile->is_open()) {
                    std::cout << "Can't read file " << fileName;
                    return 1;
                }
                infile->seekg(0, std::ios::end);
                int n = infile->tellg();
                infile->seekg(0, std::ios::beg);
                char *data = new char[n + 1];
                data[n] = 0;
                infile->read(data, n);
                infile->close();
                free(infile);
                std::cout << "Searching by name\n" << "Please, enter the flowers name:\n";
                std::string inputSearch;
                std::cin >> inputSearch;
                bool isFound = false;
                int flag = 4, counter = 0;
                std::string *buffer = new string(), *record = new string();
                std::cout << "Write two numbers for height" << '\n';
                std::cout << "One" << '\n';
                int start;
                std::cin >> start;
                std::cout << "Two" << '\n';
                int end;
                std::cin >> end;

                for (char *it = data; *it; ++it) {
                    if (isFound && *it == '|') {
                        std::cout << record << '\n';
                        break;
                    }
                    if (*it == '|') {
                        *record = "";
                        counter = 0;
                        *buffer = "";
                    }
                    if (*it != '_') {
                        *record += it;
                    } else {
                        *record += ' ';
                    }
                    if (*it == '_') {
                        counter++;
                    }
                    if (!isFound && counter < flag) {
                        continue;
                    }
                    if (!isFound && counter == flag) {
                        if (*it != '_') {
                            *buffer += it;
                        }
                    }
                    if (*it == '|' || !isFound && counter > flag) {
                        if (std::stoi(*buffer) >= start && std::stoi(*buffer) <= end)
                            isFound = true;
                    }
                }
            } else if (yourChose == exit1 || yourChose == "5") {
                return 0;
            } else {
                std::cout << "Oops, you should type only one of these" << '\n';
                std::cout << name << '\n';
                std::cout << color << '\n';
                std::cout << letter << '\n';
                std::cout << count << '\n';
                std::cout << height << '\n';
                std::cout << exit1 << '\n';
            }
        }
        if (yourChose == "0") {
            std::cout << "Are you sure?" << '\n';
            std::cin >> yourChose;
            if (yourChose == "y") {
                std::cout << "Really?" << '\n';
                yourChose = "";
                std::cin >> yourChose;
                if (yourChose == "y") {
                    std::cout << "Last check for real" << '\n';
                    yourChose = "";
                    std::cin >> yourChose;
                    if (yourChose == "y") {
                        std::cout << "Come back soon" << '\n';
                        return 0;
                    }
                }
            }
        }
        if (yourChose == "q")
            return 0;
        yourChose = "";
    }

    return 0;
}
