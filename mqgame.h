#ifndef MQGAME_H
#define MQGAME_H

#include "mqserver.h"
#include "mqposition.h"
#include "mqgrid.h"
#include "vector"

using namespace  std;
using namespace MQ;

namespace MQ
{
class MQGame
{
public:
    MQGame(int _n);
    ~MQGame();

    void requestPlay(int player_index);
    MQPosition handlePlay();
    MQPosition movePlayer(int player_index);
    bool isGameOver(); // signal others && destructors

    int number_of_players;
    int current_turen;

    MQServer* game_server;
    MQGrid* grid;

    vector<MQPosition> players_positions;

    const int num_rows = 10;
    const int num_cols = 10;
};
}
#endif // MQGAME_H
