#include "Salami.h"
using namespace std;

Salami::Salami():PizzaComponent("Salami",22.00,true){
}

Salami::~Salami(){
}

string Salami::getName(){
    return this->name;
}

double Salami::getPrice(){
    return this->price;
}

PizzaComponent* Salami::clone() const{
    return new Salami (*this);
}