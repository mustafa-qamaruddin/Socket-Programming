#include "mqgrid.h"

using namespace std;
using namespace MQ;

MQGrid::MQGrid(int _num_rows, int _num_cols)
    :num_rows{_num_rows}, num_cols{_num_cols}
{
    initGrid();
}

MQGrid::~MQGrid()
{

}

void MQGrid::initGrid()
{
    // generate empty grid
    grid.resize(num_rows);
    for(int i = 0; i < num_rows; i++)
    {
        grid[i].resize(num_cols);
        grid[i].assign(num_cols, EMPTY);
    }

    // generate snakes
    num_of_snakes = 0;
    while(num_of_snakes < MAX_SNAKES)
    {
        int r = utils.genRandom(0, num_rows);
        int c = utils.genRandom(0, num_cols);
        int l = utils.genRandom(0, MAX_LENGTH);

        MQSnake s{r, c, r+l, c, l};
        bool flag = false;

        for(int i = 0; i < (int)vec_snakes.size(); i++)
        {
            if(s.overlap(vec_snakes[i]))
            {
                flag = true;
                break;
            }
        }

        for(int i = 0; i < (int)vec_ladders.size(); i++)
        {
            if(s.overlap(vec_ladders[i]))
            {
                flag = true;
                break;
            }
        }

        if(!flag){
            vec_snakes.push_back(s);
            ++num_of_snakes;
        }
    }

    // generate ladders
}
