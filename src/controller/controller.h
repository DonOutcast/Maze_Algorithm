#ifndef MAZE_ALGORITHM_CONTROLLER_H
#define MAZE_ALGORITHM_CONTROLLER_H
#include "../model/core/core.h"

namespace s21 {
    class Controller {
    public:
        Controller();
        ~Controller() = default;

    private:
        Mode m_mode_{};
    };
} // namespace s21


#endif //MAZE_ALGORITHM_CONTROLLER_H
