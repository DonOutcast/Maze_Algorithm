#include "controller.h"


s21::Controller::Controller() : m_mode_{Mode::NONE} {}

typename s21::Mode s21::Controller::get_mode() {
    return this->m_mode_;
}

int s21::Controller::get_maze_columns() {
    return this->m_maze_->get_columns();
}

int s21::Controller::get_maze_rows() {
    return this->m_maze_->get_rows();
}

//void s21::Controller::say_hello() {
//    std::cout << "Hello World!" << std::endl;
//}




