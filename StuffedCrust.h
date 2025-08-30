#ifndef STUFFEDCRUST_H
#define STUFFEDCRUST_H
using namespace std;
#include "PizzaDecorator.h"
class Pizza;

class StuffedCrust:public PizzaDecorator{
    private:
        string name;
        double price;
    public:
        StuffedCrust(Pizza* P);
        ~StuffedCrust()=default;
        string getName();
        double getPrice();
};
#endif