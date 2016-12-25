#include "Tests/Headers/mqgridut.h"
#include "mqposition.h"

using namespace std;
using namespace MQ;

MQGridUT::MQGridUT()
{

}

MQGridUT::~MQGridUT()
{

}

void MQGridUT::testInit_data()
{
    QTest::addColumn<int>("num_rows");
    QTest::addColumn<int>("num_cols");

    QTest::newRow("TC #1") << 10 << 10;
    QTest::newRow("TC #2") << 20 << 20;
    QTest::newRow("TC #3") << 50 << 50;
}

void MQGridUT::testInit()
{
    QFETCH(int, num_rows);
    QFETCH(int, num_cols);

    vector<MQPosition> players_positions;
    players_positions.reserve(5);
    for(int i = 0; i < (int)players_positions.size(); i++)
    {
        players_positions[i] = MQPosition{0, 0};
    }

    QBENCHMARK {
        MQGrid mq{num_rows, num_cols, players_positions};

        QVERIFY(mq.num_cols == num_cols);
        QVERIFY(mq.num_rows == num_rows);
    }
}

void MQGridUT::testOverlap_data(){
    QTest::addColumn<int>("num_rows");
    QTest::addColumn<int>("num_cols");

    QTest::newRow("TC #1") << 10 << 10;
    QTest::newRow("TC #2") << 20 << 20;
    QTest::newRow("TC #3") << 50 << 50;
    QTest::newRow("TC #4") << 500 << 500;
}

void MQGridUT::testOverlap(){
    QFETCH(int, num_rows);
    QFETCH(int, num_cols);
    vector<MQPosition> players_positions;
    players_positions.reserve(5);
    for(int i = 0; i < (int)players_positions.size(); i++)
    {
        players_positions[i] = MQPosition{0, 0};
    }
    MQGrid grid{num_rows, num_cols, players_positions};
    int num_snakes = (int)grid.vec_snakes.size();
    int num_ladders = (int)grid.vec_ladders.size();
    for(int i = 0; i < num_snakes; i++)
    {
        for(int j = 0; j < num_snakes; j++)
        {
            if(i == j)
                continue;
            QVERIFY(!grid.vec_snakes[i].overlap(grid.vec_snakes[j]));
        }

        for(int j = 0; j < num_ladders; j++)
        {
            QVERIFY(!grid.vec_snakes[i].overlap(grid.vec_ladders[j]));
        }
    }
}

void MQGridUT::testNumItems_data(){
    QTest::addColumn<int>("num_rows");
    QTest::addColumn<int>("num_cols");

    QTest::newRow("TC #1") << 10 << 10;
    QTest::newRow("TC #2") << 20 << 20;
    QTest::newRow("TC #3") << 50 << 50;
    QTest::newRow("TC #4") << 500 << 500;
}

void MQGridUT::testNumItems(){
    QFETCH(int, num_rows);
    QFETCH(int, num_cols);
    vector<MQPosition> players_positions;
    players_positions.reserve(5);
    for(int i = 0; i < (int)players_positions.size(); i++)
    {
        players_positions[i] = MQPosition{0, 0};
    }
    MQGrid grid{num_rows, num_cols, players_positions};
    QVERIFY(grid.MAX_LADDERS >= (int)grid.vec_ladders.size());
    QVERIFY(grid.MAX_SNAKES >= (int)grid.vec_snakes.size());
}

void MQGridUT::testItemsBoundaries_data()
{
    QTest::addColumn<int>("num_rows");
    QTest::addColumn<int>("num_cols");

    QTest::newRow("TC #1") << 10 << 10;
    QTest::newRow("TC #2") << 20 << 20;
    QTest::newRow("TC #3") << 50 << 50;
    QTest::newRow("TC #4") << 500 << 500;
}

void MQGridUT::testItemsBoundaries()
{
    QFETCH(int, num_rows);
    QFETCH(int, num_cols);
    vector<MQPosition> players_positions;
    players_positions.reserve(5);
    for(int i = 0; i < (int)players_positions.size(); i++)
    {
        players_positions[i] = MQPosition{0, 0};
    }
    MQGrid grid{num_rows, num_cols, players_positions};

    for(int i = 0; i < grid.num_of_snakes; i++)
    {
        QVERIFY(grid.vec_snakes[i].r1 >= 0 && grid.vec_snakes[i].r1 < grid.num_rows);
        QVERIFY(grid.vec_snakes[i].r2 >= 0 && grid.vec_snakes[i].r2 < grid.num_rows);
        QVERIFY(grid.vec_snakes[i].c1 >= 0 && grid.vec_snakes[i].c1 < grid.num_cols);
        QVERIFY(grid.vec_snakes[i].c2 >= 0 && grid.vec_snakes[i].c2 < grid.num_cols);
    }
}
