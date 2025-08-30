#ifndef ORDERSTATE_H
#define ORDERSTATE_H

#include "Order.h"
class Order;

using namespace std;

class OrderState{
    public:
        virtual void print(Order* o)=0;
        virtual ~OrderState()=default;
        OrderState();
        OrderState* checkout();
        OrderState* pay();
        double tip=0;
};

#endif