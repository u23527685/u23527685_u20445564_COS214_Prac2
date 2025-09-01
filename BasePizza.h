#ifndef BASEPIZZA_H
#define BASEPIZZA_H

#include "Pizza.h"
#include "PizzaComponent.h"

using namespace std;

#include <string>

class BasePizza:public Pizza{
    public:
        BasePizza(PizzaComponent* T);
        ~BasePizza()=default;
        double getPrice() override;
        string getName() override;
        bool operator==(const Pizza& other)const;

};

#endif