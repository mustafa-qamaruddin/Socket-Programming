#include "mqgrid.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <QDataStream>

using namespace std;
using namespace MQ;

MQGrid::MQGrid(int _num_rows, int _num_cols, vector<MQPosition>* _vec_players_positions)
    :num_rows{_num_rows}, num_cols{_num_cols}, vec_players_positions{_vec_players_positions}
{
    initGrid();
    logGrid();
}

MQGrid::MQGrid(const MQGrid &rhs)
{

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

    srand(time(NULL));

    // generate snakes
    num_of_snakes = 0;
    while(num_of_snakes < MAX_SNAKES)
    {
        int r = utils.genRandom(0, num_rows-1);
        int c = utils.genRandom(0, num_cols-1);
        int l = utils.genRandom(2, MAX_LENGTH);

        if(r < 0 || r >= num_rows || r+l < 0 || r+l >= num_rows || c < 0 || c >= num_cols || l <= 0)
            continue;

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
    num_of_ladders = 0;
    while(num_of_ladders < MAX_LADDERS)
    {
        int r = utils.genRandom(0, num_rows-1);
        int c = utils.genRandom(0, num_cols-1);
        int l = utils.genRandom(2, MAX_LENGTH);

        if(r < 0 || r >= num_rows || r+l < 0 || r+l >= num_rows || c < 0 || c >= num_cols || l <= 0)
            continue;

        MQLadder lr{r, c, r+l, c, l};
        bool flag = false;

        for(int i = 0; i < (int)vec_snakes.size(); i++)
        {
            if(lr.overlap(vec_snakes[i]))
            {
                flag = true;
                break;
            }
        }

        for(int i = 0; i < (int)vec_ladders.size(); i++)
        {
            if(lr.overlap(vec_ladders[i]))
            {
                flag = true;
                break;
            }
        }

        if(!flag){
            vec_ladders.push_back(lr);
            ++num_of_ladders;
        }
    }
}

void MQGrid::logGrid()
{
    ofstream of;
    of.open("grid.txt", ios::out | ios::app);
    if(!of.is_open())
        return;

    for(int i = 0; i < num_of_snakes; i++)
    {
        of << "Snake[" << i << "]: (" << vec_snakes[i].r1 << "," << vec_snakes[i].c1 << ") -> (" << vec_snakes[i].r2 << "," << vec_snakes[i].c2 << ")\r\n";
    }

    for(int i = 0; i < num_of_ladders; i++)
    {
        of << "Ladder[" << i << "]: (" << vec_ladders[i].r1 << "," << vec_ladders[i].c1 << ") -> (" << vec_ladders[i].r2 << "," << vec_ladders[i].c2 << ")\r\n";
    }

    cout << "\r\n\r\n";
    of.close();
}

void MQGrid::setPlayersPositions(vector<MQPosition>* _vec_players_positions)
{
    vec_players_positions = _vec_players_positions;
}
