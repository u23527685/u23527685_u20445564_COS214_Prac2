#include "Feta.h"
using namespace std;

Feta::Feta():PizzaComponent("Feta Cheese",18.00,true){
}

Feta::~Feta(){
}

string Feta::getName(){
    return this->name;
}

double Feta::getPrice(){
    return this->price;
}

PizzaComponent* Feta::clone() const{
    return new Feta (*this);
}