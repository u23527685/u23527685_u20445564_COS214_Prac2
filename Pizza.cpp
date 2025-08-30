#include "Pizza.h"
#include <string>
#include <iostream>
using namespace std;

Pizza::Pizza(){

}

void Pizza::printPizza(){
    cout<<getName()<<" : R"<<getPrice()<<endl;
}
