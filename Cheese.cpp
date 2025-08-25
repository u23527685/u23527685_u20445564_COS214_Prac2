#include "Cheese.h"
using namespace std;

Cheese::Cheese():PizzaComponent("Cheese",15.00,true){
}

Cheese::~Cheese(){
}

string Cheese::getName(){
    return this->name;
}

double Cheese::getPrice(){
    return this->price;
}