#ifndef REGULARPRICE_H
#define REGULARPRICE_H
#include "DiscountStrategy.h"
using namespace std;
class RegularPrice : public DiscountStrategy{
    public:
        virtual int applyDiscount(double totalPrice, int pizzaCount);
        virtual string getDiscountName();
};
#endif