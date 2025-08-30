#include "Customer.h"
#include <iostream>

Customer::Customer(const string& name) : customerName(name) {
    cout << "Customer " << customerName << " registered for notifications." << endl;
}

Customer::~Customer() {
    cout << "Customer " << customerName << " unregistered." << endl;
}

void Customer::update(string message) {
    cout << "[CUSTOMER NOTIFICATION - " << customerName << "] " 
         << message << endl;
}

string Customer::getName() {
    return customerName;
}