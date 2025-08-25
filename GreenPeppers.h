#ifndef GREENPEPPERS_H
#define GREENPEPPERS_H
#include "PizzaComponent.h"
using namespace std;
class GreenPeppers: public PizzaComponent{
    public:
        GreenPeppers();
        ~GreenPeppers();
        string getName();
        double getPrice();
};
#endif