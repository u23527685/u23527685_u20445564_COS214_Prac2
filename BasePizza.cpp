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

bool BasePizza::operator==(const Pizza& other)const{
    if(!other.toppings)
        return false;
    return this->toppings==other.toppings;
}