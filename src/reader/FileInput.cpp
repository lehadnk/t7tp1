/**
 * @author Alexey Zauzin
 * FileInput.cpp
 * Contains file input component that loads scripts from the file system
 */

#include <fstream>
#include <filesystem>
#include "FileInput.h"
#include <regex>

std::string FileInput::getFileContents(std::string path) {
    std::__fs::filesystem::path cwd = std::__fs::filesystem::current_path();
    auto fileName = path[0] == '/' ? cwd.string() + path : cwd.string() + '/' + path;
    std::fstream f(fileName, std::fstream::in);
    std::string s;
    getline(f, s, '\0');
    if (s == "") {
        throw std::runtime_error("Unable to read from file: " + fileName);
    }

    s = std::regex_replace(s, std::regex("\\\\n"), "\n");

    return s;
}
