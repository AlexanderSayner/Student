#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int mode;
    cout << "1 - auto mode, 0 - manual\n";
    cin >> mode;

    auto fileName = "database.txt";

    // Заполнение файла
    ofstream outfile(fileName);
    if (!outfile) {
        cout << "Can't create file " << fileName;
        return -1;
    }
    string name, color;
    int number, height;
    char isBlossom = 'y';

    string buffer;
    if (mode) {
        name = "Cactus";
        color = "Green";
        number = 11;
        height = 40;
        buffer = name + "_" + color + "_" + isBlossom + "_" + to_string(number) + "_" + to_string(height) + "|";
        name = "Rose";
        color = "Red";
        number = 13;
        height = 25;
        buffer =
                buffer + name + "_" + color + "_" + isBlossom + "_" + to_string(number) + "_" + to_string(height) + "|";
    } else {
        bool isOneMore = true;
        while (isOneMore) {
            cout << "Flower Name, please:" << '\n';
            cin >> name;
            cout << "Flower color is:" << '\n';
            cin >> color;
            cout << "Is it blossom? y/n" << '\n';
            cin >> isBlossom;
            cout << "How many flowers?" << '\n';
            cin >> number;
            cout << "Flower height" << '\n';
            cin >> height;
            buffer += name + "_" + color + "_" + isBlossom + "_" + to_string(number) + "_" + to_string(height) + "|";
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
        if (isFound && (i == '|' || i == '\n')) {
            cout << "Got it:\n" << buffer << '\n';
            break;
        }

        if (i == '|' || i == '\n') {
            buffer = "";
        }
    }

    return 0;
}
