#include "Pizza.h"
#include <iostream>

void Pizza::printPizza() {
    std::cout << "Pizza: " << getName() << std::endl;
    std::cout << "Price: R" << getPrice() << std::endl;
}

// PizzaComponent.cpp
#include "PizzaComponent.h"

// PizzaComponent::PizzaComponent(const std::string& name, double price) 
//     : name(name), price(price) {
// }
