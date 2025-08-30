#ifndef TOPPINGGROUP_H
#define TOPPINGGROUP_H
#include "PizzaComponent.h"
class PizzaComponent;
using namespace std;
#include <list>
class ToppingGroup: public PizzaComponent{
    public:
        ToppingGroup(string name);
        ~ToppingGroup();
        string getName();
        double getPrice();
        void add(PizzaComponent* component);
        PizzaComponent* clone() const override;
    private:
        list<PizzaComponent*> toppings;
};
#endif