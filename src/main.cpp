#include <iostream>
#include <Stack/Stack.h>
#include "Maze.h"
#include <LinkedList/LinkedList.h>
#include "Vec.h"

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
Vec findNeighbour(std::string* maze, const LinkedList::LinkedList<char>& walls, Vec currPos)
{
    if (!walls.contains(maze[currPos.y + 1][currPos.x]))
        return Vec{currPos.y + 1, currPos.x};

    else if (!walls.contains(maze[currPos.y][currPos.x + 1]))
        return Vec{currPos.y, currPos.x + 1};

    else if (!walls.contains(maze[currPos.y - 1][currPos.x]))
        return Vec{currPos.y - 1, currPos.x};

    else if (!walls.contains(maze[currPos.y][currPos.x - 1]))
        return Vec{currPos.y, currPos.x - 1};

    return Vec{-1, -1};
}

int main()
{
    std::string mazeNames[5]{"maze.txt", "maze2.txt", "maze3.txt", "maze4.txt", "mazex.txt"};

    auto* walls = new LinkedList::LinkedList<char>();
    walls->add('+');
    walls->add('-');
    walls->add('|');
    walls->add('*');
    walls->add('#');

    for (const std::string& name : mazeNames) {
        auto* solution = new Stack::Stack<Vec>();
        Maze* maze = new Maze(name);

        if (maze == nullptr)
            return 1;

        Vec beginning = findBeginning(*maze);
        Vec end = findEnd(*maze);

        Vec currPos = beginning;
        while (currPos != end) {
            Vec neighbour = findNeighbour(maze->maze, *walls, currPos);

            if (neighbour.y != -1 && neighbour.x != -1) {
                solution->push(currPos);
                maze->maze[solution->top()->data.y][solution->top()->data.x] = '#';

                currPos = neighbour;
            } else {
                maze->maze[currPos.y][currPos.x] = '*';
                maze->maze[solution->top()->data.y][solution->top()->data.x] = '*';
                solution->pop();

                currPos = solution->top()->data;
            }
        }

        maze->maze[currPos.y][currPos.x] = '#';

        std::cout << std::endl << name << ":" << std::endl;
        maze->printMaze();
        maze->writeSolution(name);

        delete solution;
        delete maze;
    }

    std::cin.get();
    return 0;
}
