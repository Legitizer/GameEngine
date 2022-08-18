#include "systemfile_manager.h"


std::string* systemfile_manager::read_file_as_string(const char* file_path){
    std::string *file_text = new std::string();

    std::ifstream f(file_path);
    //Reading file to string.
    std::string line;
    while(std::getline(f, line)) {
        *file_text += line;
        *file_text += '\n';
    }
    f.close();

    return file_text;
}

char* systemfile_manager::read_file(const char* file_path){
    std::string *file_text = read_file_as_string(file_path);
    //Copying string to a writable address
    char* writable = new char[file_text->size() + 1];
    std::copy(file_text->begin(), file_text->end(), writable);
    writable[file_text->size()] = '\0';

    delete file_text;
    return writable;
}