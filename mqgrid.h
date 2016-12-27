#ifndef MQGRID_H
#define MQGRID_H

#include <vector>
#include "mqsnake.h"
#include "mqladder.h"
#include "mqutilities.h"
#include "mqposition.h"

using namespace std;

namespace MQ
{
    class MQGrid
    {
    public:
        MQGrid(int _num_rows, int _num_cols, vector<MQPosition> *_vec_players_positions);
        MQGrid(const MQGrid& rhs);
        ~MQGrid();
        void setPlayersPositions(vector<MQPosition>* _vec_players_positions);

        void initGrid();
        void logGrid();

        const int EMPTY = 0;
        const int LADDER = 1;
        const int SNAKE = 2;

        const int MAX_LADDERS = 4;
        const int MAX_SNAKES = 3;
        const int MAX_LENGTH = 6;

        int num_rows;
        int num_cols;

        int num_of_ladders;
        int num_of_snakes;

        vector<MQ::MQSnake> vec_snakes;
        vector<MQ::MQLadder> vec_ladders;
        vector<MQ::MQPosition>* vec_players_positions;

        vector<vector<int> > grid;

        MQ::MQUtilities utils;
    };
}
#endif // MQGRID_H
