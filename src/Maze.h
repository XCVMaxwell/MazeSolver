#ifndef MAZESOLVER_MAZE_H
#define MAZESOLVER_MAZE_H


class Maze
{
public:
    int width;

    int height;

    std::string* maze = nullptr;

    Maze(const std::string& fileName);

    ~Maze() = default;

    void loadMaze(const std::string& fileName);

    void determineDimensions(const std::string& fileName);

    void printMaze() const;

    void writeSolution(const std::string& mazeName) const;
};


#endif //MAZESOLVER_MAZE_H
