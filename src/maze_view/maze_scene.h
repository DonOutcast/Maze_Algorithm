#ifndef MAZE_SCENE_H
#define MAZE_SCENE_H
#include <QWidget>
#include <QPaintEvent>
#include <QPointF>
#include <QMouseEvent>
#include <QString>
#include <QColor>
#include <QPainter>
#include <QPen>

#include <memory>
#include "../model/core/core.h"
#include "../controller/controller.h"
#include "../model/core/matrix.h"


class MazeScene final: public QWidget {

    Q_OBJECT
    Q_DISABLE_COPY(MazeScene)

public:
    explicit MazeScene(QWidget *parent = nullptr);
    ~MazeScene() final = default;
    auto set_controller(const std::shared_ptr<s21::Controller>& controller) -> void;
private:
    s21::Mode m_mode_ {};
    s21::Matrix<bool> m_vertical_walls {};
    s21::Matrix<bool> m_horizontal_walls {};
    std::shared_ptr<s21::Controller> m_controller_ {};
    int               m_rows_ {};
    int               m_columns_ {};
    int               m_clickCounter {};
    QPoint            m_beginPosition {};
    QPoint            m_endPosition   {};
    bool              isNeedSolution {};
    static constexpr int lineWidth {2};
    static constexpr double m_window_size_  {500};
    const QString purpleColor {"#CC0099"};

    auto paintEvent(QPaintEvent* event) -> void override;
    auto mousePressEvent(QMouseEvent* event) -> void override;

    auto get_painter() -> QPainter;



};

#endif // MAZE_SCENE_H
