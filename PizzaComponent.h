#ifndef PIZZACOMPONENT_H
#define PIZZACOMPONENT_H
using namespace std;
#include<string>

class PizzaComponent{
    protected:
        string name;
        double price;
    public:
        bool topping;
        virtual string getName()=0;
        virtual double getPrice()=0;
        virtual ~PizzaComponent()=default;
        virtual PizzaComponent* clone() const=0;
        PizzaComponent(string name, double price,bool top);
        bool operator==(const PizzaComponent& other)const;
};
#endif