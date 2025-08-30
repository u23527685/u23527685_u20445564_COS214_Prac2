#ifndef REGULARPRICE_H
#define REGULARPRICE_H
#include "DiscountStrategy.h"
using namespace std;
class RegularPrice : public DiscountStrategy{
    public:
        RegularPrice();
        virtual double applyDiscount(double totalPrice);
        string getDiscountName();
};
#endif