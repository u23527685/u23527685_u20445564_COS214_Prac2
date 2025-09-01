#include "Menus.h"
#include "Observer.h"
#include "Pizza.h"
#include <iostream>

Menus::Menus() {}

Menus::~Menus() {
    for (size_t i = 0; i < pizzas.size(); ++i) {
        //delete pizzas[i];
    }
    pizzas.clear();//used  by vector and sets size to 0
}

void Menus::addObserver(Observer* observer) {
    if (observer != NULL) {
        observers.push_back(observer);
        cout<<observer->getName()<<" Added"<<endl;
    }
}

void Menus::removeObserver(Observer* observer) {
    for (size_t i = 0; i < observers.size(); ++i) {
        if (observers[i] == observer) {
            observers.erase(observers.begin() + i);
            break;
        }
    }
}

void Menus::addPizza(Pizza* pizza) {
    if (pizza != NULL) {
        pizzas.push_back(pizza);
        notifyObservers("New pizza added to menu: " + pizza->getName());
    }
}

void Menus::removePizza(Pizza* pizza) {
    for (size_t i = 0; i < pizzas.size(); ++i) {
        if (pizzas[i] == pizza) {
            std::string pizzaName = pizza->getName();
            pizzas.erase(pizzas.begin() + i);
            notifyObservers("Pizza removed from menu: " + pizzaName);
            break;

        }
    }

}
