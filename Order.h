#ifndef ORDER_H
#define ORDER_H

#include "Pizza.h"
#include "OrderState.h"
#include "DiscountStrategy.h"
#include "RegularPrice.h"
#include <vector>
using namespace std;

class OrderState;
class DiscountStrategy;

class Order{
    friend class OrderState;
    private:
        vector<Pizza*> pizzas;
        bool family=false;
        OrderState* state;
        DiscountStrategy* discount=new RegularPrice();
    public:
        void print();
        int getSize();
        double getTotal();
        void addPizza(Pizza* p);
        bool getFamilyValidation();
        Order();
        Order(bool fam);
        ~Order();
        void checkOut();
        void pay();
        void printOrder();
        void printDiscount();
        //double getdisprice();
};

#endif