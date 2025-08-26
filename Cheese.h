#ifndef CHESE_H
#define CHESE_H
#include "PizzaComponent.h"
using namespace std;
class Cheese: public PizzaComponent{
    public:
        Cheese();
        ~Cheese();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif
