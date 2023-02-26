#include "Maze.h"

#  include <iostream>

namespace s21
{
    int setCounter = 1;

    Maze::Maze(int width, int height) {
        this->height = height;
        this->width = width;
        srand((unsigned) time(NULL));
    }

    std::vector<std::vector< int > > Maze::GetVerWalls( void ) const {
        return verWalls;
    }

    void Maze::SetVerWalls( std::vector<std::vector< int > >& verWalls ) {
        this->verWalls = verWalls;
    }

    std::vector<std::vector< int > > Maze::GetHorWalls( void ) const {
        return horWalls;
    }

    void Maze::SetHorWalls( std::vector<std::vector< int > >& horWalls ) {
        this->horWalls = horWalls;
    }


    void Maze::Generate(void) {
        std::vector< int > tempLine(width, 0);

        for (std::size_t i = 0; i < height-1; ++i) {
            setupUniqSets(tempLine);
            addVertWalls(tempLine, i);
            addHorWalls(tempLine, i);
            checkHorWalls(tempLine, i);
            setupNewLine(tempLine, i);
        }

        addLastLine(tempLine);
    }

    void Maze::setupUniqSets(std::vector< int > &line) {
        for (std::size_t i = 0; i != width; ++i) {
            if (line[i] == 0) {
                line[i] = setCounter;
                setCounter++;
            }
        }
    }

    void Maze::mergeSets(std::vector< int >& line, std::size_t pos) {
        int nextRight = line[pos+1];
        for (std::size_t i = 0; i != width; ++i) {
            if (line[i] == nextRight) {
                line[i] = line[pos];
            }
        }
    }

    void Maze::addVertWalls(std::vector< int >& line, std::size_t row) {
        std::vector< int > currWalls(width, 0);
        for (std::size_t i = 0; i != width-1; ++i) {
            bool wallChoice = rand() % 2 == 0;
            if (wallChoice || line[i] == line[i+1]) {
                currWalls[i] = 1;
            } else {
                mergeSets(line, i);
            }
        }

        currWalls[width-1] = 1;

        verWalls.push_back(currWalls);
    }


    void Maze::addHorWalls(std::vector< int >& line, std::size_t row) {
        auto countSet = [](const std::vector< int >& line, std::size_t pos) {
            int counter = 0;
            for (std::size_t i = 0; i < line.size(); ++i) {
                if (line[i] == line[pos]) {
                    counter++;
                }
            }

            return counter;
        };

        std::vector< int > currWalls(width, 0);
        for (std::size_t i = 0; i < width; i++) {
            bool wallChoice = rand() % 2 == 0;
            if (wallChoice && countSet(line, i) != 1) {
                currWalls[i] = 1;
            }
        }

        horWalls.push_back(currWalls);
    }

    void Maze::checkHorWalls(std::vector< int >& line, std::size_t row) {
        auto countHorWalls = [](const std::vector< std::vector< int > >& horWalls, 
                const std::vector< int >& line, std::size_t pos, std::size_t row) {
            int counter = 0;
            for (std::size_t i = 0; i < line.size(); ++i) {
                if (line[i] == line[pos] && horWalls[row][i] == 0) {
                    counter++;
                }
            }

            return counter;
        };

        for (std::size_t i = 0; i < width; ++i) {
            if (countHorWalls(horWalls, line, i, row) == 0) {
                horWalls[row][i] = 0;
            }
        }
    }

    void Maze::setupNewLine(std::vector< int >& line, std::size_t row) {
        for (std::size_t i = 0; i != width; ++i) {
            if (horWalls[row][i] == 1) {
                line[i] = 0;
            }
        }
    }

    void Maze::addLastLine(std::vector< int >& line) {      
        setupUniqSets(line);
        addVertWalls(line, height-1);
        addHorWalls(line, height-1);

        for (std::size_t i = 0; i != width-1; ++i) {
            if (line[i] != line[i+1]) {
                verWalls[height-1][i] = 0;
                mergeSets(line, i);
            }

            horWalls[height-1][i] = 1;
        }

        horWalls[height-1][width-1] = 1;
    }


} // namespace s21

