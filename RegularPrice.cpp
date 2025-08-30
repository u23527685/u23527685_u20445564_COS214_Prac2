#include "RegularPrice.h"
#include <iostream>
#include "DiscountStrategy.h"

RegularPrice::RegularPrice(Order* order) : DiscountStrategy(order) {}

int RegularPrice::applyDiscount(double totalPrice)
{   //0% discount
    return static_cast<int>(totalPrice);    
}
string RegularPrice::getDiscountName(){
        return "Regular Price";
}
