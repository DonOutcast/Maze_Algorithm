#ifndef CORE_H
#define CORE_H
#include <random>
namespace s21 {
    struct Coordinate final {
        int x{};
        int y{};

        Coordinate() = default;
        ~Coordinate() = default;
        Coordinate(const Coordinate&) = default;
        Coordinate(int new_x, int new_y);
        Coordinate& operator=(const Coordinate& other);
    };

    bool operator==(const Coordinate& lhs, const Coordinate& rhs);
    bool operator!=(const Coordinate& lhs, const Coordinate& rhs);
    Coordinate operator+(const Coordinate& lhs, const Coordinate& rhs);


    enum class Mode {
        NONE,
        MAZE,
        CAVE
    };

    bool random_bool();
    bool percent_random_bool(int percent);
}

#endif //  CORE_H

