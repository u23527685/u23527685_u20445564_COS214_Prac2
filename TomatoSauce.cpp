#include "TomatoSauce.h"
using namespace std;

TomatoSauce::TomatoSauce():PizzaComponent("Tomato Sauce",5.00,false){
}

TomatoSauce::~TomatoSauce(){
}

string TomatoSauce::getName(){
    return this->name;
}

double TomatoSauce::getPrice(){
    return this->price;
}