#include "controller.h"


s21::Controller::Controller() : m_mode_{Mode::NONE} {}

typename s21::Mode s21::Controller::get_mode() {
    return this->m_mode_;
}





