#include "Maze.h"

#include <iostream>

int main() {
    s21::Maze maze(10, 10);

    maze.Generate();

    for (const auto& row : maze.GetVerWalls()) {
        for (auto elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;

    for (const auto& row : maze.GetHorWalls()) {
        for (auto elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}