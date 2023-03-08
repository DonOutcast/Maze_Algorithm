#include "core.h"

s21::Coordinate::Coordinate(int new_x, int new_y): x{new_x}, y{new_y} {}

s21::Coordinate &s21::Coordinate::operator=(const s21::Coordinate &other) {
    x = other.x;
    y = other.y;
    return *this;
}

bool s21::operator==(const Coordinate& lhs, const Coordinate& rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

bool s21::operator!=(const Coordinate &lhs, const Coordinate &rhs) {
    return lhs.x != rhs.x || lhs.y != rhs.y;
}

s21::Coordinate s21::operator+(const Coordinate &lhs, const Coordinate &rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}


bool s21::random_bool() {
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<int> dist{0, 1};
    return static_cast<bool>(dist(engine));
}


bool s21::percent_random_bool(int percent) {
    std::random_device rd;
    std::default_random_engine engine{rd()};
    std::uniform_int_distribution<int> dist{0, 100};
    return dist(engine) < percent;
}

