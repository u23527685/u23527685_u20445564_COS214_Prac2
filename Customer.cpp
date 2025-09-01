#include "Customer.h"
#include <iostream>

Customer::Customer(const string& name) : customerName(name) {
    cout << "Customer " << customerName << " registered for notifications." << endl;
}

Customer::~Customer() {
    cout << "Customer " << customerName << " unregistered." << endl;
}

void Customer::update(string message) {
    cout << "[CUSTOMER NOTIFICATION - " << customerName << "] "<< message << endl;
}

string Customer::getName()const {
    return customerName;
}

bool Customer::operator==(const Observer &other) const
{
    return (this->getName() == other.getName());

}
