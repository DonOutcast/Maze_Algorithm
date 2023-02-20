//
// Created by Lymond Glenda on 2/20/23.
//

#ifndef MAZE_ALGORITHM_MAZE_H
#define MAZE_ALGORITHM_MAZE_H

namespace s21 {
    class Maze final {
    public:
        Maze() = default;
        ~Maze() = default;
        Maze(const Maze&) = delete;
        Maze(Maze&&) = delete;
        auto operator=(const Maze&) -> Maze& = delete;
        auto operator=(Maze&&) -> Maze&& = delete;

        [[nodiscard]]  int get_rows();
        [[nodiscard]]  int get_columns();

    private:
        int m_rows_{};
        int m_columns_{};

    };
}

#endif //MAZE_ALGORITHM_MAZE_H
