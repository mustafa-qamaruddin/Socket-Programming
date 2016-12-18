#include "mqutilities.h"
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace MQ;

MQUtilities::MQUtilities()
{

}

int MQUtilities::genRandom(int lower, int upper) const
{
    srand(time(0));
    return (lower + (rand() * 100) / upper);
}
