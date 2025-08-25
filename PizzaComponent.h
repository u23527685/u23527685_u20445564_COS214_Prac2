#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H
using namespace std;
#include<string>

class PizzaComponent{
    protected:
        string name;
        double price;
        bool topping;
    public:
        virtual string getName()=0;
        virtual double getPrice()=0;
        virtual ~PizzaComponent();
        PizzaComponent(string name, double price,bool top);

};
#endif