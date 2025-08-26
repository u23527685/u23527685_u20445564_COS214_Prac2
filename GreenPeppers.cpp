#include "GreenPeppers.h"
using namespace std;

GreenPeppers::GreenPeppers():PizzaComponent("Green Peppers",10.00,true){
}

GreenPeppers::~GreenPeppers(){
}

string GreenPeppers::getName(){
    return this->name;
}

double GreenPeppers::getPrice(){
    return this->price;
}

PizzaComponent* GreenPeppers::clone() const{
    return new GreenPeppers (*this);
}