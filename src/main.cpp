#include <iostream>
#include <Stack/Stack.h>
#include "Maze.h"
#include <LinkedList/LinkedList.h>
#include "Vec.h"
#include <memory>
#include <future>
#include <array>
#include <string>

// Finds the beginning of the maze and returns it in a vector
Vec findBeginning(const Maze& maze)
{
    for (int i = 0; i < maze.height; i++) {
        if (maze.maze[i][0] == ' ')
            return Vec{i, 0};
    }
}

// Finds the end of the maze and returns in in a vector
Vec findEnd(const Maze& maze)
{
    for (int i = 0; i < maze.height; i++) {
        if (maze.maze[i][maze.width] == ' ')
            return Vec{i, maze.width};
    }
}

// Finds a neighbor of a vector that the current node can move to
// Checks S, E, N, W
Vec findNeighbour(std::string* maze, const std::shared_ptr<LinkedList::LinkedList<char>> walls, const Vec& currPos)
{
    if (!walls->contains(maze[currPos.y + 1][currPos.x]))
        return Vec{currPos.y + 1, currPos.x};
    
    else if (!walls->contains(maze[currPos.y][currPos.x + 1]))
        return Vec{currPos.y, currPos.x + 1};

    else if (!walls->contains(maze[currPos.y - 1][currPos.x]))
        return Vec{currPos.y - 1, currPos.x};

    else if (!walls->contains(maze[currPos.y][currPos.x - 1]))
        return Vec{currPos.y, currPos.x - 1};

    return Vec{-1, -1};
}

std::shared_ptr<Maze> solveMaze(const std::shared_ptr<LinkedList::LinkedList<char>> walls, std::string name)
{
    std::cout << "Solving maze: " << name << std::endl;

    auto solution = std::make_unique<Stack::Stack<Vec>>();
    auto maze = std::make_shared<Maze>(name);

    if (maze == nullptr)
        return nullptr;

    Vec beginning = findBeginning(*maze);
    Vec end = findEnd(*maze);

    Vec currPos = beginning;
    while (currPos != end) {
        Vec neighbour = findNeighbour(maze->maze, walls, currPos);

        if (neighbour.y != -1 && neighbour.x != -1) {
            solution->push(currPos);
            maze->maze[solution->top()->data.y][solution->top()->data.x] = '#';

            currPos = neighbour;
        }
        else {
            maze->maze[currPos.y][currPos.x] = '*';
            maze->maze[solution->top()->data.y][solution->top()->data.x] = '*';
            solution->pop();

            currPos = solution->top()->data;
        }
    }

    maze->maze[currPos.y][currPos.x] = '#';

    std::cout << "Finished solving maze: " << name << std::endl;
    return maze;
}

int main()
{
    const std::array<std::string, 5> mazeNames{ "maze.txt", "maze2.txt", "maze3.txt", "maze4.txt", "mazex.txt" };
    auto walls = std::make_shared<LinkedList::LinkedList<char>>();
    walls->add('+');
    walls->add('-');
    walls->add('|');
    walls->add('*');
    walls->add('#');

    std::array<std::future<std::shared_ptr<Maze>>, mazeNames.size()> futures;
    for (int i = 0; i < futures.size(); i++) {
        futures[i] = std::async(std::launch::async, solveMaze, walls, mazeNames[i]);
    }

    for (int i = 0; i < futures.size(); i++) {
        std::shared_ptr<Maze> maze = futures[i].get();

        std::cout << mazeNames[i] << ":" << std::endl;
        maze->printMaze();

        maze->writeSolution(mazeNames[i]);
    }

    std::cin.get();
    return 0;
}
