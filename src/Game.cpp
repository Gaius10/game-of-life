
#include "./Game.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>


Game::Game(Table *table, FileDrawer *drawer)
{
    this->table = table;
    this->drawer = drawer;
}

Game::~Game()
{
    delete this->table;
    delete this->drawer;
}

void Game::initializeFromFile(const std::string filename)
{
    // std::cout << "Initializing game from file: " << filename << std::endl;
    std::ifstream file(filename);
    std::string line;

    int lineNumber = 0;
    int columnNumber = 0;

    if (file.is_open()) {
        while(getline(file, line)) {
            for (char c : line) {
                if (c == 'X') {
                    this->table->setCell(columnNumber, lineNumber, true);
                }
                columnNumber++;
            }
            lineNumber++;
            columnNumber = 0;
        }
    }
}

void Game::run()
{
    int round = 0;
    while (true) {
        // std::cout << "Running..." << std::endl;
        this->table->update();
        this->drawer->draw(this->table);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::cout << "\r Round: " << round++ << std::flush;
    }
}