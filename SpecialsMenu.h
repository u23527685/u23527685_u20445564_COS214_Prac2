#ifndef SPECIALSMENU_H
#define SPECIALSMENU_H

#include "Menus.h"
#include <string>
using namespace std;

class SpecialsMenu : public Menus{
    public:
        SpecialsMenu();
        ~SpecialsMenu();
        virtual void notifyObservers(string message);
};
#endif