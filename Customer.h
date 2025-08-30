#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Observer.h"
#include <iostream>
#include <string>
using namespace std;

class Customer : public Observer {
private:
    string customerName;
    
public:
    Customer(const string& name);
    virtual ~Customer();
    
    virtual void update(string message);
    string getName();
};

#endif 