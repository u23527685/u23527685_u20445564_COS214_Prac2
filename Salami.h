#ifndef SALAMI_H
#define SALAMI_H
#include "PizzaComponent.h"
using namespace std;
class Salami: public PizzaComponent{
    public:
        Salami();
        ~Salami();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif