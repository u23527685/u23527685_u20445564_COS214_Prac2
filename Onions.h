#ifndef ONIONS_H
#define ONIONS_H
#include "PizzaComponent.h"
using namespace std;
class Onions: public PizzaComponent{
    public:
        Onions();
        ~Onions();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif