//
// Created by alexa on 6/18/2020.
//

#ifndef THIRD_DATASERVICE_H
#define THIRD_DATASERVICE_H

#include <string>
#include <iostream>

class DataService {
public:
    std::string search(char *data, const std::string search);

    std::string searchByColor(const std::string &data, const std::string &search);

    std::string searchByLetter(const std::string &data, const std::string &search);

    /**
     *
     * @param data
     * @param start
     * @param end
     * @param flag 3 or 4
     * @return
     */
    std::string searchByRange(const std::string &data, int start, int end, int flag);
};


#endif //THIRD_DATASERVICE_H
