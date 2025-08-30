#include "RegularPrice.h"
#include <iostream>

int RegularPrice::applyDiscount(double totalPrice, int pizzaCount)
{   //0% discount
    return static_cast<int>(totalPrice);
    
}

string RegularPrice::getDiscountName()
{
    return "Regular Price";
}
