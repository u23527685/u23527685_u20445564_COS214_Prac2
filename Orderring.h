#ifndef ORDERRING_H
#define ORDERRING_H

#include "Order.h"
#include "OrderState.h"

using namespace std;

class Orderring:public OrderState{
    public:
        void print(Order* o);
        virtual ~Orderring()=default;
        Orderring();
};

#endif