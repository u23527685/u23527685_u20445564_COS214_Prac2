#include "SpecialsMenu.h"
#include <iostream>

SpecialsMenu::SpecialsMenu() {
    cout << "Specials Menu created." << endl;
}

SpecialsMenu::~SpecialsMenu() {
    cout << "Specials Menu destroyed." << endl;
}

void SpecialsMenu::notifyObservers(string message) {
    const vector<Observer*>& obs = getObservers();
        for (size_t i = 0; i < obs.size(); ++i) {
            if (obs[i] != NULL) {
                obs[i]->update(message);
            }
        }
}