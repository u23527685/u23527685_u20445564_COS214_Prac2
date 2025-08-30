#ifndef DOUGH_H
#define DOUGH_H
#include "PizzaComponent.h"
using namespace std;
class Dough: public PizzaComponent{
    public:
        Dough();
        ~Dough();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif