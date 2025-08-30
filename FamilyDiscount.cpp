#include "FamilyDiscount.h"
#include <iostream>

FamilyDiscount::FamilyDiscount() : DiscountStrategy() {}
double FamilyDiscount::applyDiscount(double totalPrice)
{
    //15% discount
    return (totalPrice * 0.85);
    
}

string FamilyDiscount::getDiscountName(){
    return "Family Discount (15%)";
}