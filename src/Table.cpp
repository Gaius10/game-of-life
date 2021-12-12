#include "./Table.hpp"
#include <iostream>
#include <vector>

Table::Table(int x, int y)
{
    // std::cout << "Creating table..." << std::endl;
    this->sizeX = x;
    this->sizeY = y;

    this->table.resize(y);
    for (int i = 0; i < y; i++) {
        this->table[i].resize(x);
        for (int j = 0; j < x; j++) {
            this->table[i][j] = false;
        }
    }
}

vector<vector<bool>> Table::getTable()
{
    return this->table;
}

int Table::getCell(int x, int y)
{
    return this->table[x][y];
}

int Table::getSizeX()
{
    return this->sizeX;
}

int Table::getSizeY()
{
    return this->sizeY;
}

void Table::setCell(int x, int y, bool value)
{
    this->table[y][x] = value;
}

void Table::update()
{
    vector<vector<bool>> newTable;
    newTable.resize(this->sizeY);
    for (int i = 0; i < this->table.size(); i++) {
        newTable[i].resize(this->sizeX);

        for (int j = 0; j < this->table[i].size(); j++) {
            const int communityPoints = this->getCommunity(i, j);

            switch (communityPoints) {
                case 3:
                    newTable[i][j] = true;
                    break;
                case 2:
                    newTable[i][j] = this->table[i][j];
                    break;
                default:
                    newTable[i][j] = false;
                    break;
            }
        }
    }

    this->table = newTable;
}

int Table::getCommunity(int x, int y)
{
    int communityPoints = 0;

    if (x > 0 && y > 0) {
        if (this->table[x - 1][y - 1]) {
            communityPoints++;
        }
    }
    if (x > 0) {
        if (this->table[x - 1][y]) {
            communityPoints++;
        }
    }
    if (x > 0 && y < this->table[x].size() - 1) {
        if (this->table[x - 1][y + 1]) {
            communityPoints++;
        }
    }
    if (y > 0) {
        if (this->table[x][y - 1]) {
            communityPoints++;
        }
    }
    if (y < this->table[x].size() - 1) {
        if (this->table[x][y + 1]) {
            communityPoints++;
        }
    }
    if (x < this->table.size() - 1 && y > 0) {
        if (this->table[x + 1][y - 1]) {
            communityPoints++;
        }
    }
    if (x < this->table.size() - 1) {
        if (this->table[x + 1][y]) {
            communityPoints++;
        }
    }
    if (x < this->table.size() - 1 && y < this->table[x].size() - 1) {
        if (this->table[x + 1][y + 1]) {
            communityPoints++;
        }
    }

    return communityPoints;
}
