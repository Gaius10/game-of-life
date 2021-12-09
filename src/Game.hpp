#ifndef GAME_HPP
#define GAME_HPP true

#include "./Table.hpp"
#include "./FileDrawer.hpp"

class Game
{
private:
    Table *table;
    FileDrawer *drawer;
public:
    Game(Table *, FileDrawer *);
    ~Game();
    void initializeFromFile(const std::string );
    void run();
};

#endif