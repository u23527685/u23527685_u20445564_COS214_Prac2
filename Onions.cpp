#include "Onions.h"
using namespace std;

Onions::Onions():PizzaComponent("Onions",8.00,true){
}

Onions::~Onions(){
}

string Onions::getName(){
    return this->name;
}

double Onions::getPrice(){
    return this->price;
}

PizzaComponent* Onions::clone() const{
    return new Onions (*this);
}