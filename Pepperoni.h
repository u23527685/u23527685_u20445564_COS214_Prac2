#ifndef PEPPERONI_H
#define PEPPERONI_H
#include "PizzaComponent.h"
using namespace std;
class Pepperoni: public PizzaComponent{
    public:
        Pepperoni();
        ~Pepperoni();
        string getName();
        double getPrice();
};
#endif