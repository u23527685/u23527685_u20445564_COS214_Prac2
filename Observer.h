#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <string>
using namespace std;

class Observer {
    public:
        virtual void update(string message) = 0;
        virtual ~Observer(){};
};
#endif