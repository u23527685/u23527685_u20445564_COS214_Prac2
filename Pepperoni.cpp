#include "Pepperoni.h"
using namespace std;

Pepperoni::Pepperoni():PizzaComponent("Pepperoni",20.00,true){
}

Pepperoni::~Pepperoni(){
}

string Pepperoni::getName(){
    return this->name;
}

double Pepperoni::getPrice(){
    return this->price;
}

PizzaComponent* Pepperoni::clone() const{
    return new Pepperoni (*this);
}