#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H
#include <string>
using namespace std;
class DiscountStrategy{
    public:
        virtual int applyDiscount(double totalPrice, int pizzaCount) = 0;
        virtual ~DiscountStrategy() {};
        virtual string getDiscountName() = 0;

};
#endif