//
// Created by alexa on 6/18/2020.
//

#include "IntellijMenu.h"
#include "FIleReader.h"
#include "DataService.h"

int IntellijMenu::firstScreen() {
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
        std::string yourChose;
        std::cin >> yourChose;
        if (yourChose == one || yourChose == "1")
            addRecord();
        if (yourChose == two || yourChose == "2")
            seeAll();
        if (yourChose == three || yourChose == "3")
            searchScreen();
        if (yourChose == exit || yourChose == "0") {
            if (out() == 0) return 0;
        }
        if (yourChose == "q")
            return 0;
    }
    return 0;
    return 0;
    return 0;
}

int IntellijMenu::addRecord() {
    const char *fileName = "database.txt";

    int mode;
    std::cout << "1 - auto mode, 0 - manual\n";
    std::cin >> mode;

    if (mode == 1) {
        std::cout << "Welcome to Intellij Add" << '\n';
        auto fIleReader = FIleReader();
        fIleReader.clearOrCreateFile(fileName);
        auto *rose = new Flower();
        rose->name = "Rose";
        rose->color = "Red";
        rose->isBlossom = 'y';
        rose->number = 13;
        rose->height = 40;
        auto *cactus = new Flower();
        cactus->name = "Cactus";
        cactus->color = "Green";
        cactus->isBlossom = 'n';
        cactus->number = 15;
        cactus->height = 25;
        if (fIleReader.writeIntoNewFile(fileName, *rose) != 0)
            return -1;
        if (fIleReader.writeIntoNewFile(fileName, *cactus) != 0)
            return -1;
    } else {
        auto fIleReader = FIleReader();
        fIleReader.clearOrCreateFile(fileName);
        bool isOneMore = true;
        while (isOneMore) {
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
            if (fIleReader.writeIntoNewFile(fileName, *flower) != 0)
                return -1;
            std::cout << "Do you want write one more? Y/n";
            char answer;
            std::cin >> answer;
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
    return 0;
}

int IntellijMenu::seeAll() {
    std::cout << "Welcome to Intellij See" << '\n';
    const char *fileName = "database.txt";
    auto fIleReader = FIleReader();
    char *data = fIleReader.readFromTheFile(fileName);
    if (data == nullptr)
        return -1;
    std::cout << "There are file records:\n" << data;
    return 0;
}

int IntellijMenu::searchScreen() {
    std::cout << "Welcome to Intellij Search" << '\n';
    std::cout << "What do you want search for? Type it below." << '\n';
    std::string name = "Name, please - 0";
    std::string color = "Color, please - 1";
    std::string letter = "Letter, please - 2";
    std::string count = "Count, please - 3";
    std::string height = "Height, please - 4";
    std::string exit = "To the Intellij Menu, please - 5";
    std::string yourChose;
    std::cin >> yourChose;
    if (yourChose == name || yourChose == "0") {
        nameSearch();
    } else if (yourChose == color || yourChose == "1") {
        colorSearch();
    } else if (yourChose == letter || yourChose == "2") {
        letterSearch();
    } else if (yourChose == count || yourChose == "3") {
        third();
    } else if (yourChose == height || yourChose == "4") {
        fourth();
    } else if (yourChose == exit || yourChose == "5") {
        return 0;
    } else {
        std::cout << "Oops, you should type only one of these" << '\n';
        std::cout << name << '\n';
        std::cout << color << '\n';
        std::cout << letter << '\n';
        std::cout << count << '\n';
        std::cout << height << '\n';
        std::cout << exit << '\n';
        searchScreen();
    }
    return 0;
}

int IntellijMenu::nameSearch() {
    std::cout << "Tell me your name" << '\n';
    const char *fileName = "database.txt";
    auto fIleReader = FIleReader();
    char *data = fIleReader.readFromTheFile(fileName);
    std::cout << "Searching by name\n" << "Please, enter the flowers name:\n";
    std::string inputSearch;
    std::cin >> inputSearch;
    DataService dataService = DataService();
    std::string result = dataService.search(data, inputSearch);
    return 0;
}

int IntellijMenu::colorSearch() {
    std::cout << "Tell me your color" << '\n';
    const char *fileName = "database.txt";
    auto fIleReader = FIleReader();
    char *data = fIleReader.readFromTheFile(fileName);
    std::string inputSearch;
    std::cin >> inputSearch;
    DataService dataService = DataService();
    std::string result = dataService.searchByColor(data, inputSearch);
    std::cout << result << '\n';
    return 0;
}

int IntellijMenu::letterSearch() {
    std::cout << "Tell me yes or no" << '\n';
    const char *fileName = "database.txt";
    auto fIleReader = FIleReader();
    char *data = fIleReader.readFromTheFile(fileName);
    std::string inputSearch;
    std::cin >> inputSearch;
    DataService dataService = DataService();
    std::string result = dataService.searchByLetter(data, inputSearch);
    std::cout << result << '\n';
    return 0;
}

int IntellijMenu::third() {
    std::cout << "Write two numbers for count" << '\n';
    std::cout << "One" << '\n';
    int one;
    std::cin >> one;
    std::cout << "Two" << '\n';
    int two;
    std::cin >> two;
    const char *fileName = "database.txt";
    auto fIleReader = FIleReader();
    char *data = fIleReader.readFromTheFile(fileName);
    DataService dataService = DataService();
    std::string result = dataService.searchByRange(data, one, two, 3);
    std::cout << result << '\n';
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
}

int IntellijMenu::fourth() {
    std::cout << "Write two numbers for height" << '\n';
    std::cout << "One" << '\n';
    int one;
    std::cin >> one;
    std::cout << "Two" << '\n';
    int two;
    std::cin >> two;
    const char *fileName = "database.txt";
    auto fIleReader = FIleReader();
    char *data = fIleReader.readFromTheFile(fileName);
    DataService dataService = DataService();
    std::string result = dataService.searchByRange(data, one, two, 4);
    std::cout << result << '\n';
    return 0;
    return 0;
}

int IntellijMenu::out() {
    std::cout << "Are you sure?" << '\n';
    std::string yourChose;
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
    return 1;
    return 0;
    return 0;
    return 0;
    return 0;
    return 0;
}