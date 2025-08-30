#include "Orderring.h"
#include "Order.h"
#include<iostream>

using namespace std;

Orderring::Orderring(){
    
}

void Orderring::print(Order* o){
    cout<<"current Order"<<endl;
    o->print();
    cout<<"current Total"<<getdicountPrice(o)<<endl;
    o->printDiscount();
    cout<<" :R"<<getdicountPrice(o)<<endl;
}