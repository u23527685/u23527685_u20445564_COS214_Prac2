#include "DiscountStrategy.h"
#include "RegularPrice.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"
#include "Order.h"
#include <iostream>
using namespace std;


DiscountStrategy::DiscountStrategy()
{
}


DiscountStrategy* DiscountStrategy::getDiscount(Order *order)
{
    if (order->getFamilyValidation()){
        return new FamilyDiscount();
    }
    if (order->getSize() >= 5){
        return new BulkDiscount();
    }
    else {
        return new RegularPrice();
    }
}
