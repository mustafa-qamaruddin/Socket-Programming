#ifndef MQGRID_H
#define MQGRID_H

#include <vector>
#include "mqsnake.h"
#include "mqladder.h"
#include "mqutilities.h"

using namespace std;

namespace MQ
{
    class MQGrid
    {
    public:
        MQGrid(int _num_rows, int _num_cols);
        ~MQGrid();

        void initGrid();

        const int EMPTY = 0;
        const int LADDER = 1;
        const int SNAKE = 2;

        const int MAX_LADDERS = 3;
        const int MAX_SNAKES = 3;
        const int MAX_LENGTH = 5;

        int num_rows;
        int num_cols;

        int num_of_ladders;
        int num_of_snakes;

        vector<MQ::MQSnake> vec_snakes;
        vector<MQ::MQLadder> vec_ladders;

        vector<vector<int> > grid;

        MQ::MQUtilities utils;
    };
}
#endif // MQGRID_H
