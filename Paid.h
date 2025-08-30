#ifndef PAID_H
#define PAID_H

#include "Order.h"
#include "OrderState.h"

using namespace std;

class Paid:public OrderState{
    public:
        void print(Order* o);
        virtual ~Paid()=default;
        Paid(double t);
};

#endif