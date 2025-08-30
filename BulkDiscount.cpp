#include "BulkDiscount.h"
#include <iostream>

int BulkDiscount::applyDiscount(double totalPrice, int pizzaCount)
{   //10% discount on 5+ pizzas
    
    return static_cast<int>(totalPrice * 0.9);
}
string getDiscountName(){ 
    return "Bulk Orders Discount (10%)"; 
}