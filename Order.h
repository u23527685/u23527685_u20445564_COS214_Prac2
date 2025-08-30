#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "OrderState.h"
#include <vector>
using namespace std;

class OrderState;

class Order{
    private:
        vector<Pizza*> pizzas;
        bool family=false;
        OrderState* state;

    public:
        void print();
        double getTotal();
        void addPizza(Pizza* p);
        Order();
        Order(bool fam);
        ~Order();
        void checkOut();
        void pay();
        void printOrder();
};

#endif