#include "mqutilities.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using namespace MQ;

MQUtilities::MQUtilities()
{

}

int MQUtilities::genRandom(int lower, int upper) const
{
    // Box Muller Random Variable
//    double r1 = (double)rand();
//    double r2 = (double)rand();
//    double u1 = fmod(r1, 1) + 0;
//    double u2 = fmod(r2, 1) + 0;
//    double z0 = sqrt(-2 * log(u1)) * cos(2 * 3.14 * u2);
//    return z0 * (upper - lower) + lower;
    return rand() % (upper-lower) + lower;
}
