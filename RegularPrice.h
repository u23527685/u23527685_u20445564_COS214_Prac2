#ifndef REGULARPRICE_H
#define REGULARPRICE_H
#include "DiscountStrategy.h"
using namespace std;
class RegularPrice : public DiscountStrategy{
    public:
        RegularPrice(Order* order);
        virtual int applyDiscount(double totalPrice);
        virtual string getDiscountName();
};
#endif