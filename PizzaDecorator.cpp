#include "PizzaDecorator.h"
#include "Pizza.h"
using namespace std;
class Pizza;

double PizzaDecorator::getPrice(){
    return pizza->getPrice();
}

string PizzaDecorator::getName(){
    return pizza->getName();
}

PizzaDecorator::PizzaDecorator(Pizza* p){
    pizza=p;
}