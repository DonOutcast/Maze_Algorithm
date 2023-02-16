#include "maze_scene.h"



MazeScene::MazeScene(QWidget *parent)
    : QWidget{parent}, m_mode_{s21::Mode::NONE} {}

auto MazeScene::set_controller(
    const std::shared_ptr<s21::Controller> &controller) -> void {
  m_controller_ = controller;
}


