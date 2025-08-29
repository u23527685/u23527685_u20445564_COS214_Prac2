#ifndef PIZZA_H
#define PIZZA_H

#include "PizzaComponent.h"
#include <string>
using namespace std;

class Pizza{
    public:
        Pizza();
        virtual ~Pizza()=default;
        virtual double getPrice()=0;
        virtual string getName()=0;
        void printPizza();
    protected:
};

#endif