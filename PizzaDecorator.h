#ifndef PIZZADECORATOR_H
#define PIZZADECORATOR_H

#include "Pizza.h"
class Pizza;

using namespace std;

#include <string>

class PizzaDecorator:public Pizza{
    public:
        PizzaDecorator(Pizza* p);
        virtual ~PizzaDecorator()=default;
        virtual double getPrice() override;
        virtual string getName() override;
        virtual bool operator==(const Pizza& other)const;

};

#endif