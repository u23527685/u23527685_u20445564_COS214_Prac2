#include "DiscountStrategy.h"
#include "RegularPrice.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "Order.h"
#include <iostream>
using namespace std;


DiscountStrategy::DiscountStrategy(Order *order)
{
    this->order = order;
}

DiscountStrategy::~DiscountStrategy()
{
    cout<<"Deleting order discount"<<endl;
    delete order;
}

DiscountStrategy* DiscountStrategy::getDiscount(Order *order)
{
    if (order->getFamilyValidation()){
        return new FamilyDiscount(order);
    }
    if (order->getSize() >= 5){
        return new BulkDiscount(order);
    }
    else {
        return new RegularPrice(order);
    }
}
