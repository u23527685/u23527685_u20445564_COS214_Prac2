#include "ExtraCheese.h"
#include "Pizza.h"
#include <string>

ExtraCheese::ExtraCheese(Pizza* P) : PizzaDecorator(P){
    name="Stuffed Crust";
    price=20.00;
}

string ExtraCheese::getName(){
    return PizzaDecorator::getName() + name;
}

double ExtraCheese::getPrice(){
    return PizzaDecorator::getPrice() + price;
}