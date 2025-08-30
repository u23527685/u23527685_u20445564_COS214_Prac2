#include "BasePizza.h"

BasePizza::BasePizza(PizzaComponent* T){
    toppings=T;
}

double BasePizza::getPrice(){
    return toppings->getPrice();
}

string BasePizza::getName(){
    return toppings->getName();
}