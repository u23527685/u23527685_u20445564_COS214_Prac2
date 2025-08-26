#ifndef FETA_H
#define FETA_H
#include "PizzaComponent.h"
using namespace std;
class Feta: public PizzaComponent{
    public:
        Feta();
        ~Feta();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif