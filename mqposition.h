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

        MQPosition(const MQPosition& rhs){
            row = rhs.row;
            col = rhs.col;
        }

        MQPosition& operator=(const MQPosition& rhs)
        {
            row = rhs.row;
            col = rhs.col;
            return *this;
        }

        ~MQPosition()
        {
        }

        int row;
        int col;
    };
}
#endif // MQPOSITION_H
