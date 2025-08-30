#ifndef CHECKOUT_H
#define CHECKOUT_H

#include "Order.h"
#include "OrderState.h"

using namespace std;

class CheckOut:public OrderState{
    public:
        void print(Order* o);
        virtual ~CheckOut()=default;
        CheckOut();
};

#endif