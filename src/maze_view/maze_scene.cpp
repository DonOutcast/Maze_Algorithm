#include "maze_scene.h"



MazeScene::MazeScene(QWidget *parent)
    : QWidget{parent}, m_mode_{s21::Mode::NONE} {}

auto MazeScene::set_controller(
    const std::shared_ptr<s21::Controller> &controller) -> void {
  m_controller_ = controller;
}

auto MazeScene::mousePressEvent(QMouseEvent* event) -> void{
    if (this->m_controller_->get_mode() != s21::Mode::MAZE)
        return;

}

auto MazeScene::paintEvent(QPaintEvent* event) -> void {

}
