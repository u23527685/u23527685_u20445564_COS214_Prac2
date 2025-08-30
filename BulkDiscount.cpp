#include "BulkDiscount.h"
#include <iostream>

BulkDiscount::BulkDiscount() : DiscountStrategy() {}

double BulkDiscount::applyDiscount(double totalPrice)
{   //10% discount on 5+ pizzas
    return (totalPrice * 0.9);
}

string BulkDiscount::getDiscountName(){ 
    return "Bulk Orders Discount (10%)"; 
}