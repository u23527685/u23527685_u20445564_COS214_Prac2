#include "PizzaMenu.h"
#include <iostream>

PizzaMenu::PizzaMenu() {
    cout << "Pizza Menu created." << endl;
}

PizzaMenu::~PizzaMenu() {
    cout << "Pizza Menu destroyed." << endl;
}

void PizzaMenu::notifyObservers(string message) {
    const vector<Observer*>& obs = getObservers();
    for (size_t i = 0; i < obs.size(); ++i) {
        if (obs[i] != NULL) {
            obs[i]->update(message);
        }
    }
}