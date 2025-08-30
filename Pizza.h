#ifndef PIZZA_H
#define PIZZA_H

#include "Observer.h"
#include <string>
using namespace std;

class Pizza{
    private:
        string name;
        double price;
    
    public:
        virtual ~Pizza();
        virtual double getPrice() = 0;
        virtual string getName() = 0;
        void printPizza();
};
#endif