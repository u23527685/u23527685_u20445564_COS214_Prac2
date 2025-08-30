#ifndef EXTRACHEESE_H
#define EXTRACHEESE_H
using namespace std;
#include "PizzaDecorator.h"
class Pizza;

class ExtraCheese:public PizzaDecorator{
    private:
        string name;
        double price;
    public:
        ExtraCheese(Pizza* P);
        ~ExtraCheese()=default;
        string getName();
        double getPrice();
};
#endif