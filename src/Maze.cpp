#include <fstream>
#include <iostream>
#include <algorithm>
#include <windows.h>
#include <string>
#include "Maze.h"

Maze::Maze(const std::string &fileName)
{
    determineDimensions(fileName);
    loadMaze(fileName);
}

// Populates the width and height of the maze
void Maze::determineDimensions(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open()) {
        int count = 0;
        while (std::getline(file, line)) {
            if (count == 0) {
                // Removes line end characters just to determine the width. File is unedited.
                line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
                line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());

                this->width = (uint16_t) line.size() - 1;
            }

            count++;
        }

        this->height = count;

        file.close();
    }
    else {
        std::cout << "Unable to open file!";
    }
}

// Reads maze from file in to array of strings
void Maze::loadMaze(const std::string& fileName)
{
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open()) {
        this->maze = new std::string[this->height];

        int count = 0;
        while (std::getline(file, line)) {
            maze[count] = line;
            count++;
        }

        file.close();
    }
    else {
        std::cout << "Unable to open file!";
    }
}

// Prints maze to console coloring the solution in red
void Maze::printMaze() const
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleMode(handle, ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j <= this->width; ++j) {
            if (this->maze[i][j] == '*')
                std::cout << ' ';

            else if (this->maze[i][j] == '#')
                std::cout << "\x1b[1;31m" << this->maze[i][j] << "\x1b[0m";

            else
                std::cout << this->maze[i][j];

        }
        std::cout << std::endl;
    }
}

// Writes solution to file
void Maze::writeSolution(const std::string& mazeName) const
{
    std::ofstream file;
    std::string newName = mazeName + " Solution";
    file.open(newName);

    for (int i = 0; i < this->height; i++) {
        std::string line = this->maze[i];

        for (char c : line) {
            if (c == '*')
                file << ' ';
            else
                file << c;
        }

        file << std::endl;
    }

    file.close();
}
