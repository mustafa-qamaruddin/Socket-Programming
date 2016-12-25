#ifndef MQRENDER_H
#define MQRENDER_H

#include "mqgrid.h"

#include <QWidget>

namespace MQ
{
    class MQRender: public QWidget
    {
        Q_OBJECT
    public:
        MQRender(MQGrid* grid, QWidget* parent = 0);
        ~MQRender();
        void paintEvent(QPaintEvent* event);
        QPoint mapFromParent(const QPoint &) const;
        void drawGrid();
        void drawPlayers();
        int normalizeY(int raw_y);

        void setShape();
        void setBrush();
        void setPen();
        void setPainter();

        QPixmap* pix_map;
        QPainter* painter;
        QPen* pen;
        QBrush* brush;

        MQGrid* grid;

        const int MQWIDTH = 300;
        const int MQHEIGHT = 300;

        int cell_width;
        int cell_height;
    private slots:
        void shapeChanged();
        void penChanged();
        void brushChanged();
    };
}

#endif
