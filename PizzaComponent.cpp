using namespace std;
#include "PizzaComponent.h"
#include <string>

PizzaComponent::PizzaComponent(string name, double price, bool top){
    this->name=name;
    this->price=price;
    this->topping=top;
}

string toLower(const std::string& str) {
    string result = str;
    for (char &c : result) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
    }
    return result;
}

 bool PizzaComponent::operator==(const PizzaComponent& other)const{
    return  toLower(this->name)==toLower(other.name);
 }

