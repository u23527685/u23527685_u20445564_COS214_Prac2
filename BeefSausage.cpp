#include "BeefSausage.h"
using namespace std;

BeefSausage::BeefSausage():PizzaComponent("Beef Sausage",25.00,true){
}

BeefSausage::~BeefSausage(){
}

string BeefSausage::getName(){
    return this->name;
}

double BeefSausage::getPrice(){
    return this->price;
}

PizzaComponent* BeefSausage::clone() const{
    return new BeefSausage (*this);
}