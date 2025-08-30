#include "FAMILYDISCOUNT.h"
#include "iostream"

int FamilyDiscount::applyDiscount(double totalPrice, int pizzaCount)
{
    //15% discount
    return static_cast<int>(totalPrice * 0.85);
}

string getDiscountName(){
    return "Family Discount (15%)";
}