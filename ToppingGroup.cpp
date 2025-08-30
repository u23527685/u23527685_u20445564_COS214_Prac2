#include "ToppingGroup.h"
#include "Dough.h"
#include "TomatoSauce.h"
#include <string>
using namespace std;

ToppingGroup::ToppingGroup(string name):PizzaComponent(name,0.00,true){ 
    add(new TomatoSauce());
    add(new Dough());
}

ToppingGroup::~ToppingGroup(){
    for (PizzaComponent* topping : toppings) {
        delete topping;
    }
}

string ToppingGroup::getName(){
    string out= this->name +"(";
    for (list<PizzaComponent*>::iterator it=toppings.begin();it!=toppings.end();it++){
        if((*it)->topping)
            out+= (*it)->getName()+",";
    }
    if (out!=this->name+"(") {
        out.pop_back();
    }
    out+=")";
    return out;
}

double ToppingGroup::getPrice(){
    return this->price;
}

void ToppingGroup::add(PizzaComponent* component){
    if(component!=nullptr){
        toppings.push_back(component);
        this->price+=component->getPrice();
    }
}

PizzaComponent* ToppingGroup::clone() const {
    ToppingGroup* newGroup = new ToppingGroup(name);
    for (const auto& topping : toppings) {
        newGroup->add(topping->clone()); // Assuming PizzaComponent has a clone method
    }
    return newGroup;
}
