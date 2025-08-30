#include "StuffedCrust.h"
#include "Pizza.h"
#include <string>

StuffedCrust::StuffedCrust(Pizza* P) : PizzaDecorator(P){
    name="Stuffed Crust";
    price=20.00;
}

string StuffedCrust::getName(){
    return PizzaDecorator::getName() +", EX:"+ name;
}

double StuffedCrust::getPrice(){
    return PizzaDecorator::getPrice() + price;
}