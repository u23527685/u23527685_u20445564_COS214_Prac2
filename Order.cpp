#include"Order.h"
#include "Pizza.h"
#include "OrderState.h"
#include "Orderring.h"
#include <vector>
#include <iostream>
using namespace std;
//discount variable
Order::Order(){
    state=new Orderring();
}

Order::Order(bool fam){
    family=fam;
    state=new Orderring();
}
int Order::getSize(){
    return this->pizzas.size();
}
void Order::addPizza(Pizza* p){
    if(p!=nullptr)
        pizzas.push_back(p);
}

bool Order::getFamilyValidation()
{
    return family;
}

void Order::print(){
    for(size_t i=0; i<pizzas.size();i++)
        pizzas[i]->printPizza();
}

double Order::getTotal(){
    double out=0;
     for(size_t i=0; i<pizzas.size();i++)
        out+=pizzas[i]->getPrice();
    return (out);
}

void Order::checkOut(){
    OrderState* newState=state->checkout();
    delete state; 
    state=newState;
    printOrder();
}

void Order::pay(){
    OrderState* newState=state->pay();
    delete state; 
    state=newState;
    printOrder();
}

Order::~Order(){
    delete state;
    delete discount;
}

 void Order::printOrder(){
    state->print(this);
 }

 void Order::printDiscount(){
    DiscountStrategy* newdiscount=discount->getDiscount(this);
    delete discount;
    discount = newdiscount;
    cout<<discount->getDiscountName();
 }