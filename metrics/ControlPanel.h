//
// Created by alexa on 6/1/2020.
//

#ifndef METRICS_CONTROLPANEL_H
#define METRICS_CONTROLPANEL_H

#include "FIleReader.h"
#include "DataService.h"

class ControlPanel {
public:
    int autoInput(const char *fileName);

    int manualInput(const char *fileName);

private:
    int search(const char *fileName, FIleReader *fIleReader);
};


#endif //METRICS_CONTROLPANEL_H
