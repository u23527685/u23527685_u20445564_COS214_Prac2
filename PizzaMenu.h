#ifndef PIZZAMENUS_H
#define PIZZAMENUS_H

#include "Menus.h"
#include <string>
using namespace std;

class PizzaMenu : public Menus{
    public:
        PizzaMenu();
        ~PizzaMenu();
        virtual void notifyObservers(string message);
};
#endif