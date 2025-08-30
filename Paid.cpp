#include "Paid.h"
#include "Order.h"
#include<iostream>

using namespace std;

Paid::Paid(double t){
    tip=t;
}

void Paid::print(Order* o){
    cout<<"Paid Order"<<endl;
    o->print();
    cout<<"Pizza Total R"<<o->getTotal()<<endl;
    cout<<"Tip:R"<<tip<<endl;
    cout<<"Total Paid R"<<o->getTotal()+tip<<endl;
}