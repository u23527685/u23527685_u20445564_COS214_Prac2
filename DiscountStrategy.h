#ifndef DISCOUNTSTRATEGY_H
#define DISCOUNTSTRATEGY_H

class Order;
#include <string>
using namespace std;
class DiscountStrategy{
    public:
        DiscountStrategy();
        virtual double applyDiscount(double totalPrice) = 0;
        virtual ~DiscountStrategy()=default;
        virtual string getDiscountName()=0;
        DiscountStrategy* getDiscount(Order* order);

};
#endif