#include "PizzaComponent.h"
#include "BeefSausage.h"
#include "Cheese.h"
#include "Dough.h"
#include "Feta.h"
#include "GreenPeppers.h"
#include "Mushrooms.h"
#include "Olives.h"
#include "Onions.h"
#include "Pepperoni.h"
#include "Salami.h"
#include "TomatoSauce.h"
#include "ToppingGroup.h"
#include "Pizza.h"
#include "BasePizza.h"
#include "PizzaDecorator.h"
#include "ExtraCheese.h"
#include "StuffedCrust.h"
#include "Order.h"
#include "DiscountStrategy.h"
#include<iostream>

using namespace std;

int main(){
    ToppingGroup vegan("vegeterian");
    ToppingGroup meat("meat lovers");
    //vegan pizza
    vegan.add(new Onions());
    vegan.add(new GreenPeppers());
    vegan.add(new Mushrooms());
    vegan.add(new Feta());

    //meat pizza
    meat.add(new Salami());
    meat.add(new BeefSausage());
    meat.add(new Cheese());

    cout<<vegan.getName()<<endl;
    cout<<vegan.getPrice()<<endl;

    cout<<meat.getName()<<endl;
    cout<<meat.getPrice()<<endl;

    //Meat Deluxe
    ToppingGroup meatdel("meat lovers deluxe");
    meatdel.add(meat.clone());
    meatdel.add(new Pepperoni());

    cout<<meatdel.getName()<<endl;
    cout<<meatdel.getPrice()<<endl;

    //Base Pizza
    BasePizza b1(&meat);
    BasePizza b2(&meatdel);

    //Decorators
    StuffedCrust sc(&b1);
    ExtraCheese ec(&b2);
    StuffedCrust dd(&ec);

    sc.printPizza();
    ec.printPizza();
    dd.printPizza();

    //order
    Order order;
    order.addPizza(&sc);
    order.addPizza(&ec);
    order.addPizza(&dd);
    order.addPizza(&b1);
    order.addPizza(&b2);
    //discount

    cout<<"Orderring print"<<endl;
    order.printOrder();
    order.checkOut();

    cout<<"Checkout print"<<endl;
    order.printOrder();
    order.pay();

    cout<<"Paid print"<<endl;
    order.printOrder();
    return 0;
}