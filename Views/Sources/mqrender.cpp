#include "Views/Headers/mqrender.h"

#include <QPainter>
#include <QWidget>

using namespace std;
using namespace MQ;

MQRender::~MQRender()
{

}

MQRender::MQRender(MQGrid* _grid, QWidget* parent)
    :QWidget(parent), grid{_grid}
{
    setPen();
    setBrush();
    setPainter();
    resize(MQWIDTH, MQHEIGHT);
    move(10, 70);
    drawGrid();
    drawPlayers();
}

QPoint MQRender::mapFromParent(const QPoint& parent_pos) const
{
    QPoint p{parent_pos.x() + 100, parent_pos.y() + 100};
    return p;
}

void MQRender::paintEvent(QPaintEvent* event)
{
}

void MQRender::drawGrid()
{
    painter->drawRect(0, 0, MQWIDTH, MQHEIGHT);

    cell_width = MQWIDTH / grid->num_cols;
    cell_height = MQHEIGHT / grid->num_rows;

    for(int i = 0; i < grid->num_rows; i++)
    {
        for(int j = 0; j < grid->num_cols; j++)
        {
            painter->drawRect(i*cell_height, j*cell_width, i*cell_height+cell_height, j*cell_width+cell_width);
        }
    }

    painter->setPen(QPen(Qt::red, 0, Qt::DashDotDotLine, Qt::RoundCap));
    for(int i = 0; i < grid->num_of_snakes; i++)
    {
        int x1 = grid->vec_snakes[i].c1 * cell_width;
        int y2 = normalizeY((grid->vec_snakes[i].r2+1) * cell_height);
        int h = abs(grid->vec_snakes[i].r2-grid->vec_snakes[i].r1+1) * cell_height;

        painter->drawRoundedRect(QRectF(x1, y2, cell_width, h), 10, 10);
    }

    painter->setPen(QPen(Qt::green, 0, Qt::DashDotDotLine, Qt::RoundCap));
    for(int i = 0; i < grid->num_of_ladders; i++)
    {
        int x1 = grid->vec_ladders[i].c1 * cell_width;
        int y2 = normalizeY((grid->vec_ladders[i].r2+1) * cell_height);
        int h = abs(grid->vec_ladders[i].r2-grid->vec_ladders[i].r1+1) * cell_height;

        painter->drawRoundedRect(QRectF(x1, y2, cell_width, h), 10, 10);
    }

    // restore to optimize
}

void MQRender::drawPlayers()
{
    int num_players = (int)grid->vec_players_positions->size();
    for(int i = 0; i < num_players; i++)
    {
        QPen new_pen{Qt::blue};
        painter->setPen(new_pen);

        MQPosition p = grid->vec_players_positions->at(i);
        int x = p.col;
        int y = p.row;

        QPoint c{};
        double dx = x * cell_width + cell_width / 4 + 2 * i * cell_width / 4;
        c.setX(dx);
        double dy = y * cell_height + cell_height / 4 + 2 * i * cell_height / 4;
        c.setY(normalizeY(dy));

        painter->drawEllipse(c, cell_width / 4, cell_height / 4);
        painter->drawText(c, QString::number(i+1));
    }
}

void MQRender::setPainter()
{
    pix_map = new QPixmap(MQWIDTH, MQHEIGHT);
    painter = new QPainter(pix_map);
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(*pen);
    painter->setBrush(*brush);
}

void MQRender::setPen()
{
    pen = new QPen(Qt::black, 0, Qt::SolidLine, Qt::RoundCap);
}

void MQRender::setBrush()
{
    brush = new QBrush(Qt::white, Qt::SolidPattern);
}

void MQRender::penChanged()
{

}

void MQRender::shapeChanged()
{

}

void MQRender::brushChanged()
{

}

int MQRender::normalizeY(int raw_y)
{
    return (MQHEIGHT - raw_y);
}
