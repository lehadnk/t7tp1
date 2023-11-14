/**
 * @author Alexey Zauzin
 * FileInput.h
 * Contains headers for FileInput class
 */

#ifndef T7TP1_FILEINPUT_H
#define T7TP1_FILEINPUT_H

#include "iostream";

class FileInput {
public:
    std::string getFileContents(std::string path);
};


#endif //T7TP1_FILEINPUT_H
