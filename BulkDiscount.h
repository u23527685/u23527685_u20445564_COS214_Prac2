#ifndef BULKDISCOUNT_H
#define BULKDISCOUNT_H
#include "DiscountStrategy.h"

class BulkDiscount : public DiscountStrategy{
    public:
        BulkDiscount(Order* order);
        virtual int applyDiscount(double totalPrice);
        virtual string getDiscountName();
};
#endif