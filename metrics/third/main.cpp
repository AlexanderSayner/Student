#include <iostream>
#include "ControlPanel.h"

using namespace std;

int main() {
    int mode;
    cout << "1 - auto mode, 0 - manual\n";
    cin >> mode;

    const char *fileName = "database.txt";
    auto controlPanel = ControlPanel();
    if (mode == 0) {
        return controlPanel.manualInput(fileName);
    } else {
        return controlPanel.autoInput(fileName);
    }
}
