#include <iostream>
#include <fstream>

using namespace std;

/**
 * ЛИнейная программа
 * @param mode 0 - ручной ввод, 1 - автоматический
 * @return
 */
int first(int mode) {
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

    string buffer = "";
    if (mode) {
        name = "Cactus";
        color = "Green";
        isBlossom = 'y';
        buffer = name + "_" + color + "_" + isBlossom + "|";
        name = "Rose";
        color = "Red";
        buffer = buffer + name + "_" + color + "_" + isBlossom + "\n";
    } else {
        bool isOneMore = true;
        while (isOneMore) {
            cout << "Flower Name, please:" << '\n';
            cin >> name;
            cout << "Flower color is:" << '\n';
            cin >> color;
            cout << "Is it blossom? y/n" << '\n';
            cin >> isBlossom;
            buffer = buffer + name + "_" + color + "_" + isBlossom + "|";
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
    for (infile >> s; !infile.eof(); infile >> s)
        cout << s << endl;
    cout << "There are file records:\n" << s << '\n';

    // Поиск по файлу
    return 0;
}

int second() {
    return 0;
}

int third() {
    return 0;
}

int main() {
    first(0);
    return 0;
}
