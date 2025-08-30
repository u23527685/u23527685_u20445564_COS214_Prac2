#include "CheckOut.h"
#include "Order.h"
#include<iostream>

using namespace std;

CheckOut::CheckOut(){
    
}

void CheckOut::print(Order* o){
    cout<<"Order"<<endl;
    o->print();
    cout<<"Pizza Total R"<<o->getTotal()<<endl;
    cout<<"Enter Tip amount:R";
    cin>>tip;
    cout<<"Total R"<<o->getTotal()+tip<<endl;
}

