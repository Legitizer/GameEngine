#ifndef _systemfile_manager_H
#define _systemfile_manager_H

#include <iostream>
#include <fstream>
#include <string>

class systemfile_manager {
public:
    static char* read_file(const char* file_path);
    static std::string* read_file_as_string(const char* file_path);
private:
};

#endif