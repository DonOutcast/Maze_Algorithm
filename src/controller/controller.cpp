#include "controller.h"


s21::Controller::Controller() : m_mode_{Mode::NONE} {}

typename s21::Mode s21::Controller::get_mode() {
    return this->m_mode_;
}

const int s21::Controller::get_maze_columns() {
    return this->m_maze_->columns();
}

const int s21::Controller::get_maze_rows() {
    return this->m_maze_->rows();
}




