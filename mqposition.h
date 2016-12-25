#ifndef MQPOSITION_H
#define MQPOSITION_H
namespace MQ
{
    class MQPosition
    {
    public:
        MQPosition(int _row, int _col)
            :row{_row}, col{_col}
        {
        }

        ~MQPosition()
        {
        }

        int row;
        int col;
    };
}
#endif // MQPOSITION_H
