#include "./FileDrawer.hpp"
#include <fstream>

FileDrawer::FileDrawer(const std::string filename)
{
    this->filename = filename;
}


void FileDrawer::draw(Table *table)
{
    // std::cout << "Drawing on " << this->filename << "..." << std::endl;
    std::ofstream f(this->filename, std::ios::out);
    for (vector<bool> line : table->getTable())
    {
        for (bool cell : line)
        {
            if (cell)
                f << "X";
            else
                f << " ";
        }
        f << std::endl;
    }
    f.close();
}

// void FileDrawer::draw(Table *table)
// {
//     std::cout << "Drawing " << filename << "..." << std::endl;

//     for (vector<bool> line : table->getTable())
//     {
//         for (bool cell : line)
//         {
//             if (cell)
//                 std::cout << "#";
//             else
//                 std::cout << " ";
//         }
//         std::cout << std::endl;
//     }
// }