#ifndef OLIVES_H
#define OLIVES_H
#include "PizzaComponent.h"
using namespace std;
class Olives: public PizzaComponent{
    public:
        Olives();
        ~Olives();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif