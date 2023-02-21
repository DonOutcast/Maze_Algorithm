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
    if (event->button() == Qt::LeftButton) {
        if (m_clickCounter > 1) {
            return ;
        } else if (this->m_clickCounter == 0) {
            this->m_beginPosition = event->pos();
        } else {
            this->m_endPosition = event->pos();
            ++m_clickCounter;
            isNeedSolution = true;
        }
    } else if (event->button() == Qt::RightButton) {
        isNeedSolution = false;
        m_clickCounter = 0;
    }
    repaint();
}

auto MazeScene::get_painter() -> QPainter {

}

auto MazeScene::paintEvent(QPaintEvent* event) -> void {
    QPainter painter{this};
    QPen pen{Qt::white};
    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(1, 1, 1, this->m_window_size_ - 1);
    painter.drawLine(1, 1,this->m_window_size_ , 1);
    painter.drawLine(this->m_window_size_  - 1, 1, this->m_window_size_  - 1, this->m_window_size_  - 1);
    painter.drawLine(1, this->m_window_size_  - 1, this->m_window_size_  - 1, this->m_window_size_  - 1);
    m_mode_ = m_controller_->get_mode();
    if (this->m_mode_ == s21::Mode::NONE) {
        return;
    }
    if (this->m_mode_ == s21::Mode::MAZE) {
        this->m_rows_ = this->m_controller_->get_maze_rows();
        this->m_columns_ = this->m_controller_->get_maze_columns();
        this->m_vertical_walls.resize(this->m_rows_, this->m_columns_);
        this->m_horizontal_walls.resize(this->m_rows_, this->m_columns_);
        double width{this->m_window_size_  / this-> m_columns_};
        double height{this->m_window_size_ / this->m_rows_};
        for (int i{1}; i <= this->m_rows_; i++) {
            for (int j{1}; j <= this->m_columns_; j++) {
                if (this->m_vertical_walls(i -1, j - 1) && j != this->m_columns_) {
                    painter.drawLine(QPointF{j * width, (i - 1) * height}, QPointF{j * width, i * height});
                }
                if (this->m_horizontal_walls(i - 1, j - 1) && i != this->m_rows_) {
                    painter.drawLine(QPointF{(j - 1) * width, i * height}, QPointF{j * width, i * height});
                }
            }
        }







    }

}
