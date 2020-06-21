#include <iostream>
#include "ControlPanel.h"
#include "IntellijMenu.h"

using namespace std;

int main() {

    auto intellijMenu=IntellijMenu();
    return intellijMenu.firstScreen();
}
