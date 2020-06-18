#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int mode;
    cout << "1 - auto mode, 0 - manual\n";
    cin >> mode;

    auto *fileName = "database.txt";

    // Заполнение файла
    auto *outfile = new ofstream();
    outfile->open(fileName);
    if (!*outfile) {
        cout << "Can't create file " << *fileName;
        return -1;
    }
    auto *name = new string();
    auto *color = new string();
    char *isBlossom = new char('y');

    auto *buffer = new string("");
    if (mode) {
        *name = "Cactus";
        *color = "Green";
        *buffer = *name + "_" + *color + "_" + *isBlossom + "|";
        *name = "Rose";
        *color = "Red";
        *buffer = *buffer + *name + "_" + *color + "_" + *isBlossom + "|";
    } else {
        bool *isOneMore = new bool(true);
        while (*isOneMore) {
            cout << "Flower Name, please:" << '\n';
            cin >> *name;
            cout << "Flower color is:" << '\n';
            cin >> *color;
            cout << "Is it blossom? y/n" << '\n';
            cin >> *isBlossom;
            *buffer = *buffer + *name + "_" + *color + "_" + *isBlossom + "|";
            cout << "Do you want write one more? Y/n";
            char answer;
            cin >> answer;
            switch (answer) {
                case 'Y':
                case 'y': {
                    *isOneMore = true;
                    break;
                }
                default:
                    *isOneMore = false;
                    break;
            }
        }
        delete isOneMore;
    }
    *outfile << *buffer << endl;
    outfile->close();
    free(outfile);

    // Считываение файла
    auto *infile = new ifstream(fileName, ios::binary);
    if (!infile->is_open()) {
        cout << "Can't open file " << *fileName;
        return -1;
    }
    infile->seekg(0, ios::end);
    int n = infile->tellg();
    infile->seekg(0, ios::beg);
    char *s = new char[n + 1];
    s[n] = 0;
    infile->read(s, n);
    infile->close();
    free(infile);
    cout << "There are file records:\n" << s;

    // Поиск по файлу
    cout << "Searching by name:\n" << "Please, enter the flowers name:\n";
    string input;
    cin >> input;
    auto *search = new string(input);
    delete buffer;
    buffer = new string("");
    bool *isFound = new bool(false);

    for (char *it = s; *it; ++it) {
        auto *buf = new string(*buffer + *it);
        delete buffer;
        buffer = new string(*buf);
        delete buf;

        if (*buffer == *search && !*isFound) {
            *isFound = true;
        }
        if (*isFound && (*it == '|' || *it == '\n')) {
            cout << "Got it:\n" << *buffer << '\n';
            break;
        }

        if (*it == '|' || *it == '\n') {
            delete buffer;
            buffer = new string("");
        }
    }

    free(name);
    free(color);
    free(isBlossom);
    free(buffer);
    free(search);
    free(s);
    free(isFound);
    return 0;
}
