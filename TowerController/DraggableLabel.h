#pragma once

#include <QObject>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QVBoxLayout>
#include <QPushButton>

class DraggableLabel : public QLabel
{
    Q_OBJECT
public:
    DraggableLabel();

public:
    explicit DraggableLabel(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags())
        : QLabel(parent, f)
    {
        setStyleSheet("background-color: rgba(0, 100, 100, 128); border: 2px solid black;");
        setText("可拖动的标签\n透明度: 50%");
        setAlignment(Qt::AlignCenter);
        setMinimumSize(150, 80);
        stoney = 90;
    }

    // 返回QLabel的大小
    QSize getLabelSize() const {
        return size();
    }

signals:
    void labelMoved(const QPoint& pos, const QSize& size);

protected:
    void mousePressEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton) {
            m_dragStartPosition = event->pos();
        }
        QLabel::mousePressEvent(event);
    }

    void mouseMoveEvent(QMouseEvent* event) override {
        if (event->buttons() & Qt::LeftButton) {

            QPoint delta = event->pos() - m_dragStartPosition;

            qDebug() << event->pos();
            qDebug() << "delta" << delta;
            //            delta.setY(stoney);
            //            move(pos() + delta);
            move(pos().x()+delta.x(), pos().y());

        }
        QLabel::mouseMoveEvent(event);
    }

    void mouseReleaseEvent(QMouseEvent* event) override {
        if (event->button() == Qt::LeftButton) {
            emit labelMoved(pos(), size());
        }
        QLabel::mouseReleaseEvent(event);
    }

private:
    QPoint m_dragStartPosition;
    int stoney;
};