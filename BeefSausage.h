#ifndef BEEFSAUSAGE_H
#define BEEFSAUSAGE_H
#include "PizzaComponent.h"
using namespace std;
class BeefSausage: public PizzaComponent{
    public:
        BeefSausage();
        ~BeefSausage();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif