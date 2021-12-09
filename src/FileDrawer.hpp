#ifndef FILE_DRAWER_HPP
#define FILE_DRAWER_HPP true

#include "./Table.hpp"
#include <iostream>

class FileDrawer
{
private:
    std::string filename;
public:
    FileDrawer(const std::string);
    void draw(Table *);
};

#endif