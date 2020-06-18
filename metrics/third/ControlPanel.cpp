//
// Created by alexa on 6/18/2020.
//

#include "ControlPanel.h"

int ControlPanel::autoInput(const char *fileName) {
    auto fIleReader = FIleReader();
    fIleReader.clearOrCreateFile(fileName);
    auto *rose = new Flower();
    rose->name = "Rose";
    rose->color = "Red";
    rose->isBlossom = 'y';
    auto *cactus = new Flower();
    cactus->name = "Cactus";
    cactus->color = "Green";
    cactus->isBlossom = 'n';
    if (fIleReader.writeIntoNewFile(fileName, *rose) != 0)
        return -1;
    if (fIleReader.writeIntoNewFile(fileName, *cactus) != 0)
        return -1;
    return search(fileName, &fIleReader);
}

int ControlPanel::manualInput(const char *fileName) {
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
    return search(fileName, &fIleReader);
}

int ControlPanel::search(const char *fileName, FIleReader *fIleReader) {
    char *data = fIleReader->readFromTheFile(fileName);
    if (data == nullptr)
        return -1;
    std::cout << "There are file records:\n" << data;
    std::cout << "Searching by name\n" << "Please, enter the flowers name:\n";
    std::string inputSearch;
    std::cin >> inputSearch;
    DataService dataService = DataService();
    dataService.search(data, inputSearch);
    return 0;
}
