using namespace std;
#include "PizzaComponent.h"

PizzaComponent::PizzaComponent(string name, double price, bool top){
    this->name=name;
    this->price=price;
    this->topping=top;
}
PizzaComponent::~PizzaComponent(){}
