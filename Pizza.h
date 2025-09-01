#ifndef PIZZA_H
#define PIZZA_H

#include "PizzaComponent.h"
#include <string>
using namespace std;

class BasePizza;
class PizzaDecorator;
class Pizza{
    friend class BasePizza;
    friend class PizzaDecorator;
    private:
        PizzaComponent* toppings=nullptr;
        Pizza* pizza=nullptr;
    public:
        Pizza();
        virtual ~Pizza()=default;
        virtual double getPrice()=0;
        virtual string getName()=0;
        void printPizza();
        virtual bool operator==(const Pizza& other)const=0;
        
};
#endif