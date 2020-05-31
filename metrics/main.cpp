#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Линейная программа
 * @param mode 0 - ручной ввод, 1 - автоматический
 * @return 0 - выполнено без ошибок
 */
int firstProgram(int mode) {
    auto fileName = "database.txt";

    // Заполнение файла
    ofstream outfile(fileName);
    if (!outfile) {
        cout << "Can't create file " << fileName;
        return -1;
    }
    string name;
    string color;
    char isBlossom = 'y';

    string buffer;
    if (mode) {
        name = "Cactus";
        color = "Green";
        buffer = name + "_" + color + "_" + isBlossom + "|";
        name = "Rose";
        color = "Red";
        buffer = buffer + name + "_" + color + "_" + isBlossom + "|";
    } else {
        bool isOneMore = true;
        while (isOneMore) {
            cout << "Flower Name, please:" << '\n';
            cin >> name;
            cout << "Flower color is:" << '\n';
            cin >> color;
            cout << "Is it blossom? y/n" << '\n';
            cin >> isBlossom;
            buffer += name + "_" + color + "_" + isBlossom + "|";
            cout << "Do you want write one more? Y/n";
            char answer;
            cin >> answer;
            switch (answer) {
                case 'Y':
                case 'y': {
                    isOneMore = true;
                    break;
                }
                default:
                    isOneMore = false;
                    break;
            }
        }
    }
    outfile << buffer << endl;
    outfile.close();

    // Считываение файла
    ifstream infile(fileName);
    if (!infile.is_open()) {
        cout << "Can't open file " << fileName;
        return -1;
    }
    string s;
    infile >> s;
    infile.close();
    cout << "There are file records:\n" << s << '\n';

    // Поиск по файлу
    cout << "Searching by name:\n" << "Please, enter the flowers name:\n";
    string search;
    cin >> search;
    buffer = "";
    bool isFound = false;
    for (char i : s) {

        buffer += i;
        if (buffer == search && !isFound) {
            isFound = true;
        }
        if (isFound && i == '|') {
            cout << "Got it:\n" << buffer;
            break;
        }

        if (i == '|') {
            buffer = "";
        }
    }

    return 0;
}

/**
 * Линейка с указателями
 * @param mode 0 - ручной ввод, 1 - автоматический
 * @return 0 - выполнено без ошибок
 */
int secondProgram(int mode) {
    auto *fileName = "database.txt";

    // Заполнение файла
    ofstream outfile(fileName);
    if (!outfile) {
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
            char *answer;
            cin >> *answer;
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
        }
        delete isOneMore;
    }
    outfile << *buffer << endl;
    outfile.close();

    // Считываение файла
    ifstream infile(fileName, ios::binary);
    if (!infile.is_open()) {
        cout << "Can't open file " << *fileName;
        return -1;
    }
    infile.seekg(0, ios::end);
    int n = infile.tellg();
    infile.seekg(0, ios::beg);
    char *s = new char[n + 1];
    s[n] = 0;
    infile.read(s, n);
    cout << "There are file records:\n" << s;

    // Поиск по файлу
    cout << "Searching by name:\n" << "Please, enter the flowers name:\n";
    string input;
    cin >> input;
    string *search = new string(input);
    delete buffer;
    buffer = new string("");
    bool *isFound = new bool(false);

    for (char *it = s; *it; ++it) {
        string *buf = new string(*buffer + *it);
        delete buffer;
        buffer = new string(*buf);

        if (*buffer == *search && !*isFound) {
            *isFound = true;
        }
        if (*isFound && *it == '|') {
            cout << "Got it:\n" << *buffer;
            break;
        }

        if (*it == '|') {
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

/**
 * ООП
 * @param mode 0 - ручной ввод, 1 - автоматический
 * @return 0 - выполнено без ошибок
 */
int thirdProgram(int mode) {
    return 0;
}

int main() {
//    firstProgram(1);
    secondProgram(1);
    return 0;
}
