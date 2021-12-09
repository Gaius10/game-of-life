#ifndef TABLE_HPP
#define TABLE_HPP true

#include <vector>

using namespace std;

typedef struct {
    int x;
    int y;
} tableSize;

class Table {
private:
    int sizeX;
    int sizeY;
    vector<vector<bool>> table;
    // bool table[40][40];
public:
    Table(int, int);
    vector<vector<bool>> getTable();
    int getCell(int, int);
    int getSizeX();
    int getSizeY();
    int getCommunity(int, int);

    void setCell(int, int, bool);
    void update();
};

#endif