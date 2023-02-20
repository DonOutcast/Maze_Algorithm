#ifndef MAZE_ALGORITHM_CONTROLLER_H
#define MAZE_ALGORITHM_CONTROLLER_H
#include <memory>
#include "../model/core/core.h"
#include "../model/maze/maze.h"

namespace s21 {
    class Controller {
    public:
        Controller();
        ~Controller() = default;
        Controller(const Controller&) = delete;
        Controller(Controller&&) = delete;
        [[nodiscard]]  int get_maze_rows();
        [[nodiscard]]  int get_maze_columns();
        [[nodiscard]]  Mode get_mode();
    private:
        Mode m_mode_{};
        std::unique_ptr<Maze> m_maze_{};
    };
} // namespace s21


#endif //MAZE_ALGORITHM_CONTROLLER_H
