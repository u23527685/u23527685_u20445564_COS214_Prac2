#ifndef MENUS_H
#define MENUS_H

#include "Pizza.h"
#include <string>
#include <vector>
using namespace std;
class Observer;
class Pizza;
class Menus{
    
    private:
        vector <Observer*> observers;
        vector <Pizza*> pizzas;
    public:
        Menus();
        virtual ~Menus();
        void addObserver(Observer* observer);
        void removeObserver(Observer* observer);
        void addPizza(Pizza* pizza);
        void removePizza(Pizza* pizza);
        virtual void notifyObservers(string message) = 0;
        const vector<Observer*>& getObservers() const {return observers;};
};
#endif