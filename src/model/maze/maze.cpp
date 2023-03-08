#include "maze.h"

int s21::Maze::get_columns() {
    return this->m_rows_;
}

int s21::Maze::get_rows() {
    return this->m_columns_;
}

std::vector<std::pair<int, int>> s21::Maze::search_path(const std::pair<int, int> &start, const std::pair<int, int> &finish) {
    int length{1};
    std::vector<Coordinate> points;
    Coordinate begin{start.first, start.second};
    Coordinate end{finish.first, finish.second};
    points.push_back(begin);
    m_grid.resize(this->m_rows_, this->m_columns_);
    m_grid.fill(-1);
    m_grid(begin.x, begin.y) = 0;
    while (!points.empty()) {
        Coordinate checkEnd = wave(points, end, length);
        if (checkEnd == end) {
            points.clear();
        }
        ++length;
    }
    auto coordinateVector = restore_path(begin, end);
    std::vector<std::pair<int, int>> pathVector;
    for (auto& item : coordinateVector) {
        pathVector.emplace_back(item.x, item.y);
    }
    return pathVector;
}

s21::Coordinate s21::Maze::wave(std::vector<Coordinate> &points, const s21::Coordinate &end, int len) {
    std::vector<s21::Coordinate> new_points;
    std::vector<s21::Coordinate> dir_vector;
    this->fill_direction(dir_vector);
    for (auto& pos : points) {
        for (auto& direction : dir_vector) {
            auto point = this->step(new_points, pos, direction, len);
            if (point == end) {
                points.clear();
                return end;
            }
        }
    }
    points = new_points;
    return s21::Coordinate{};
}

void s21::Maze::fill_direction(std::vector<Coordinate> &direction) {
    direction.emplace_back(this->up_, this->skip_);
    direction.emplace_back(this->down_, this->skip_);
    direction.emplace_back(this->skip_, this->right_);
    direction.emplace_back(this->skip_, this->left_);
}

s21::Coordinate s21::Maze::step(std::vector<Coordinate> &new_points, const s21::Coordinate &position, Coordinate& direction, int len) {
    s21::Coordinate check{position + direction};
    s21::Coordinate result{-1, -1};
    if (this->check_step(position, direction.x, direction.y) && this->m_grid(check.x, check.y) == -1) {
        new_points.push_back(check);
        this->m_grid(check.x, check.y) = len;
        result = check;
    }
    return result;
}

bool s21::Maze::check_step(const s21::Coordinate position, const int direction_x, const int direction_y) {
    bool result = false;
    if (position.x + direction_x < 0 || position.y + direction_y < 0) {
        result = false;
    } else if (direction_y == this->right_ && !m_vertical_walls(position.x, position.y)) {
        result = true;
    } else if (direction_y == this->left_ && !m_vertical_walls(position.x, position.y + direction_y)) {
        result = true;
    } else if (direction_x == this->up_ && !m_horizontal_walls(position.x + direction_x, position.y)) {
        result = true;
    } else if (direction_x == this->down_ && !m_horizontal_walls(position.x, position.y)) {
        result = true;
    }
    return result;
}

std::vector<s21::Coordinate> s21::Maze::restore_path(const s21::Coordinate &begin, const s21::Coordinate &end) {
    return std::vector<Coordinate>();
}
