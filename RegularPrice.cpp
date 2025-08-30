#include "RegularPrice.h"
#include <iostream>

RegularPrice::RegularPrice(){}

double RegularPrice::applyDiscount(double totalPrice)
{   //0% discount
    return (totalPrice);    
}
string RegularPrice::getDiscountName(){
        return "Regular Price";
}
