#include <iostream>

#include "./src/FileDrawer.hpp"
#include "./src/Game.hpp"
#include "./src/Table.hpp"

int main(int argc, char **argv)
{
    Game game(
        new Table(80, 40),
        new FileDrawer("gaming.txt")
    );

    game.initializeFromFile("gaming.txt");
    game.run();
    return 0;
}