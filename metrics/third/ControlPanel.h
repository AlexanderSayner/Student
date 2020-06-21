//
// Created by alexa on 6/18/2020.
//

#ifndef THIRD_CONTROLPANEL_H
#define THIRD_CONTROLPANEL_H

#include "FIleReader.h"
#include "DataService.h"

class ControlPanel {
public:
    int autoInput(const char *fileName);

    int manualInput(const char *fileName);

private:
    int search(const char *fileName, FIleReader *fIleReader);
};


#endif //THIRD_CONTROLPANEL_H
