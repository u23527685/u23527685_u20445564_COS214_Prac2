#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H
#include "DiscountStrategy.h"

class BulkDiscount : public DiscountStrategy{
    public:
        virtual int applyDiscount(double totalPrice, int pizzaCount);
        virtual string getDiscountName();
};
#endif