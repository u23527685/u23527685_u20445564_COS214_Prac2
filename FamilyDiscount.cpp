#include "FAMILYDISCOUNT.h"
#include <iostream>
#include "DiscountStrategy.h"

FamilyDiscount::FamilyDiscount(Order* order) : DiscountStrategy(order) {}
int FamilyDiscount::applyDiscount(double totalPrice)
{
    //15% discount
    return static_cast<int>(totalPrice * 0.85);
    
}

string FamilyDiscount::getDiscountName(){
    return "Family Discount (15%)";
}