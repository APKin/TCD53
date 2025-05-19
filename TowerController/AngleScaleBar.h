#pragma once
#include <QWidget>
#include <QPainter>

class AngleScaleBar : public QWidget
{
    Q_OBJECT
        Q_PROPERTY(int min READ min WRITE setMin)
        Q_PROPERTY(int max READ max WRITE setMax)
public:
    explicit AngleScaleBar(QWidget* parent = nullptr)
        : QWidget(parent), m_min(0), m_max(360)
    {
        setFixedHeight(80);  // 增加高度以容纳角度符号
    }

    int min() const { return m_min; }
    int max() const { return m_max; }

    void setMin(int min) { m_min = min; update(); }
    void setMax(int max) { m_max = max; update(); }

protected:
    void paintEvent(QPaintEvent* event) override
    {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        drawBackground(&painter);
        drawTicks(&painter);
        drawLabels(&painter);
    }

private:
    int m_min;
    int m_max;

    // 刻度参数配置
    const int MAJOR_TICK_INTERVAL = 30;   // 主刻度间隔
    const int MINOR_TICK_INTERVAL = 5;    // 次刻度间隔
    const int MAJOR_TICK_HEIGHT = 20;
    const int MINOR_TICK_HEIGHT = 10;
    const int LABEL_OFFSET = 25;

    void drawBackground(QPainter* painter)
    {
        painter->fillRect(rect(), Qt::white);
    }

    void drawTicks(QPainter* painter)
    {
        const int width = this->width();
        const int height = this->height();

        QPen pen(Qt::black);
        pen.setWidth(1);
        painter->setPen(pen);

        // 绘制所有刻度线
        for (int i = m_min; i <= m_max; i += MINOR_TICK_INTERVAL) {
            int xPos = static_cast<double>(i - m_min) / (m_max - m_min) * width;

            if (i % MAJOR_TICK_INTERVAL == 0) { // 主刻度
                painter->drawLine(xPos, height - MAJOR_TICK_HEIGHT, xPos, height);
            }
            else { // 次刻度
                painter->drawLine(xPos, height - MINOR_TICK_HEIGHT, xPos, height);
            }
        }
    }

    void drawLabels(QPainter* painter)
    {
        const int width = this->width();
        const int height = this->height();

        painter->setPen(Qt::black);
        QFont font = painter->font();
        font.setPointSize(9);
        painter->setFont(font);

        // 绘制主刻度标签（带度数符号）
        for (int i = m_min; i <= m_max; i += MAJOR_TICK_INTERVAL) {
            int xPos = static_cast<double>(i - m_min) / (m_max - m_min) * width;
            QString text = QString::number(i) + "°";

            QRect textRect = painter->fontMetrics().boundingRect(text);
            int textX = xPos - textRect.width() / 2;
            int textY = height - LABEL_OFFSET;

            painter->drawText(textX, textY, text);
        }
    }
};