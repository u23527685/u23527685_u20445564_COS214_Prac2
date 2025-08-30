#ifndef TOMATOSAUCE_H
#define TOMATOSAUCE_H
#include "PizzaComponent.h"
using namespace std;
class TomatoSauce: public PizzaComponent{
    public:
        TomatoSauce();
        ~TomatoSauce();
        string getName();
        double getPrice();
        PizzaComponent* clone() const override;
};
#endif