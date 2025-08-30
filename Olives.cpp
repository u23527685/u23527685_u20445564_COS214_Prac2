#include "Olives.h"
using namespace std;

Olives::Olives():PizzaComponent("Olives",10.00,true){
}

Olives::~Olives(){
}

string Olives::getName(){
    return this->name;
}

double Olives::getPrice(){
    return this->price;
}

PizzaComponent* Olives::clone() const{
    return new Olives (*this);
}