#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

#include "Order.h"
#include "RegularPrice.h"
#include "BulkDiscount.h"
#include "FamilyDiscount.h"

#include <string>
using namespace std;
class DiscountStrategy{
    public:
        DiscountStrategy(Order* order);
        virtual int applyDiscount(double totalPrice) = 0;
        virtual ~DiscountStrategy();
        DiscountStrategy* getDiscount(Order* order);
    private:
        Order* order;

};
#endif