#include "BulkDiscount.h"
#include <iostream>
#include "DiscountStrategy.h"

BulkDiscount::BulkDiscount(Order* order) : DiscountStrategy(order) {}

int BulkDiscount::applyDiscount(double totalPrice)
{   //10% discount on 5+ pizzas
    return static_cast<int>(totalPrice * 0.9);
}

string BulkDiscount::getDiscountName(){ 
    return "Bulk Orders Discount (10%)"; 
}