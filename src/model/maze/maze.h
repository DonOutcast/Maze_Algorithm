//
// Created by Lymond Glenda on 2/20/23.
//

#ifndef MAZE_ALGORITHM_MAZE_H
#define MAZE_ALGORITHM_MAZE_H
#include <vector>
#include "../core/matrix.h"
#include "../core/core.h"

namespace s21 {
    class Maze final {
    public:
        Maze() = default;

        ~Maze() = default;

        Maze(const Maze &) = delete;

        Maze(Maze &&) = delete;

        auto operator=(const Maze &) -> Maze & = delete;

        auto operator=(Maze &&) -> Maze && = delete;

        [[nodiscard]]  int get_rows();
        [[nodiscard]]  int get_columns();
        [[nodiscard]] Coordinate wave(std::vector<Coordinate>& points, const Coordinate& end, int len);
        [[nodiscard]] std::vector<std::pair<int, int>> search_path(const std::pair<int, int> &start, const std::pair<int, int> &finish);
        [[nodiscard]] Coordinate step(std::vector<Coordinate>& new_points, const Coordinate& position, Coordinate& direction, int len);
        [[nodiscard]] std::vector<Coordinate> restore_path(const Coordinate& begin, const Coordinate& end);

        void fill_direction(std::vector<Coordinate>& direction);
        bool check_step(const Coordinate position, const int d_x, const int d_y);

    private:
        int m_rows_{};
        int m_columns_{};
        int m_set_counter_{};
        std::vector<int> m_lineSet{};
        s21::Matrix<bool> m_horizontal_walls{};
        s21::Matrix<bool> m_vertical_walls{};
        s21::Matrix<int> m_grid{};

        static constexpr int down_ = 1;
        static constexpr int up_ = 1;
        static constexpr int left_ = 1;
        static constexpr int right_ = 1;
        static constexpr int skip_ = 0;


    };
}

#endif //MAZE_ALGORITHM_MAZE_H
