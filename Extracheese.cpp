#include "ExtraCheese.h"
#include "Pizza.h"
#include <string>

ExtraCheese::ExtraCheese(Pizza* P) : PizzaDecorator(P){
    name="Extra Cheese";
    price=12.00;
}

string ExtraCheese::getName(){
    return PizzaDecorator::getName() + name;
}

double ExtraCheese::getPrice(){
    return PizzaDecorator::getPrice() + price;
}