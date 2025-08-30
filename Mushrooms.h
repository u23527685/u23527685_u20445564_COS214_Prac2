#ifndef MUSHROOMS_H
#define MUSHROOMS_H
#include "PizzaComponent.h"
using namespace std;
class Mushrooms: public PizzaComponent{
    public:
        Mushrooms();
        ~Mushrooms();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif