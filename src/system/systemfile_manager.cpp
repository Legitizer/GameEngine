#include "systemfile_manager.h"

char* systemfile_manager::read_file(const char* file_path){
    std::string file_text;
    std::ifstream f(file_path);

    //Reading file to string.
    std::string line;
    while(std::getline(f, line)) {
        file_text += line;
        file_text += '\n';
    }
    f.close();

    //Copying string to a writable address
    char* writable = new char[file_text.size() + 1];
    std::copy(file_text.begin(), file_text.end(), writable);
    writable[file_text.size()] = '\0';
    
    return writable;
}