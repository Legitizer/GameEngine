#ifndef _SystemFileManager_H
#define _SystemFileManager_H

#include <iostream>
#include <fstream>
#include <string>

class SystemFileManager {
public:
    static char* read_file(const char* file_path);
private:
};

#endif