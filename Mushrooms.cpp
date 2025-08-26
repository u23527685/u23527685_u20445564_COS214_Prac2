#include "Mushrooms.h"
using namespace std;

Mushrooms::Mushrooms():PizzaComponent("Mushrooms",12.00,true){
}

Mushrooms::~Mushrooms(){
}

string Mushrooms::getName(){
    return this->name;
}

double Mushrooms::getPrice(){
    return this->price;
}

PizzaComponent* Mushrooms::clone() const{
    return new Mushrooms (*this);
}