#include "Dough.h"
using namespace std;

Dough::Dough():PizzaComponent("Dough",10.00,false){
}

Dough::~Dough(){
}

string Dough::getName(){
    return this->name;
}

double Dough::getPrice(){
    return this->price;
}