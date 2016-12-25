#include "mqgame.h"
#include "mqposition.h"

using namespace std;
using namespace MQ;

MQGame::MQGame(int _n)
    :number_of_players{_n}
{
    players_positions.reserve(number_of_players);
    for(int i = 0; i < (int)players_positions.size(); i++)
    {
        players_positions[i] = MQPosition{0, 0};
    }
    grid = new MQGrid(num_rows, num_cols, players_positions);
}

MQGame::~MQGame()
{

}
