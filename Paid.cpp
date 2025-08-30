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
    o->printDiscount();
    cout<<" :R"<<getdicountPrice(o)<<endl;
    cout<<"Tip:R"<<tip<<endl;
    cout<<"Total Paid R"<<getdicountPrice(o)+tip<<endl;
}