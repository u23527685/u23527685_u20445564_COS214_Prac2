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
#include "Customer.h"
#include "PizzaMenu.h"
#include "SpecialsMenu.h"
#include "Website.h"
#include "Observer.h"
#include <iostream>

using namespace std;

// 🎨 ANSI Colors
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define UNDERLINE   "\033[4m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

int main() {

    Dough d;
    TomatoSauce T;
    cout<<d.getName()<<" R"<<d.getPrice()<<" "<<T.getName()<<" R"<<T.getPrice()<<endl;

    cout<<(d==T)<<endl;

    cout << BOLD << BLUE << "-----------------  WELCOME TO PIZZA PARADISE  -----------------" << RESET << endl << endl;
    //Testing website
    Website* myWeb = new Website("Kai's Pizza Paradise");
    Website* myweb2= new Website("Jessica pizza");
    cout<<"\nSimulating updates...\n"<<endl;
    
    ToppingGroup vegan("Vegeterian");
    ToppingGroup meat("Meat Lovers");
    ToppingGroup vedandel("Vegeterian deluxe");

    // Vegan pizza
    vegan.add(new Onions());
    vegan.add(new Olives());
    vegan.add(new GreenPeppers());
    vegan.add(new Mushrooms());
    vegan.add(new Feta());
    vedandel.add(vegan.clone());


    // Meat pizza
    meat.add(new Salami());
    meat.add(new BeefSausage());
    meat.add(new Cheese());

    cout << CYAN << "Pizza: " << BOLD << vegan.getName() << RESET << " | Price: " << GREEN << "R" << vegan.getPrice() << RESET << endl;
    cout << CYAN << "Pizza: " << BOLD << meat.getName() << RESET << " | Price: " << GREEN << "R" << meat.getPrice() << RESET << endl;

    // Meat Deluxe
    ToppingGroup meatdel("Meat Lovers Deluxe");
    meatdel.add(meat.clone());
    meatdel.add(new Pepperoni());
    
    ToppingGroup meatdel2("yayaya");
    meatdel2.add(meatdel.clone());

    cout << CYAN << "Pizza: " << BOLD << meatdel.getName() << RESET << " | Price: " << GREEN << "R" << meatdel.getPrice() << RESET << endl << endl;

    // Create menus
    PizzaMenu pizzaMenu;
    SpecialsMenu specialsMenu;

    // Create customers (observers)
    Customer *jessica = new Customer("Jessica");
    Customer *alex = new Customer("Alex");

    // Add observers to menus
    cout << MAGENTA << BOLD << "\n Testing Observer Notifications..." << RESET << endl;
    pizzaMenu.addObserver(jessica);
    pizzaMenu.addObserver(alex);
    pizzaMenu.addObserver(myWeb);
    pizzaMenu.addObserver(myweb2);
    

    specialsMenu.addObserver(jessica);
    specialsMenu.addObserver(myweb2);
    //remove observer
    cout<<"Removing customer"<<endl;
    pizzaMenu.removeObserver(jessica);
    pizzaMenu.removeObserver(myweb2);
    
    // Base pizzas
    BasePizza b1(&meat);
    BasePizza b2(&meatdel);
    pizzaMenu.addPizza(&b1);
    pizzaMenu.addPizza(&b2);
    cout<<"Removing Pizzas:"<<endl;
    pizzaMenu.removePizza(&b1);
    specialsMenu.addPizza(&b2);
    cout<<(b1==b2)<<endl;
   

    
    // Decorators
    StuffedCrust sc(&b1);
    ExtraCheese ec(&b2);
    StuffedCrust dd(&ec);

    cout<<(sc==ec)<<(sc==dd)<<endl;
    cout<<(b1==sc)<<endl;

    cout << YELLOW << "\n Pizzas with Decorators:" << RESET << endl;
    sc.printPizza();
    ec.printPizza();
    dd.printPizza();

    // Order
    Order order;
    order.addPizza(&sc);
    order.addPizza(&ec);
    order.addPizza(&dd);
    order.addPizza(&b1);
    order.addPizza(&b2);
    
    Order famorder(true);
    famorder.addPizza(&sc);
    famorder.addPizza(&ec);
    famorder.addPizza(&dd);

    Order regorder;
    regorder.addPizza(&sc);
    regorder.addPizza(&ec);
    regorder.addPizza(&dd);
    regorder.addPizza(&b1);

    //Bulk
    cout << BOLD << BLUE << "\n----------------  ORDER SUMMARY : BULK ----------------" << RESET << endl;
    order.printOrder();
    order.checkOut();

    cout << BOLD << GREEN << "\n---------------- CHECKOUT -----------------" << RESET << endl;
    order.printOrder();
    order.pay();

    cout << BOLD << YELLOW << "\n---------------- PAYMENT COMPLETE  ----------------" << RESET << endl;
    order.printOrder();

    cout << BOLD << BLUE << "\n----------------- THANK YOU!  -----------------" << RESET << endl;

    //family
    cout << BOLD << BLUE << "\n----------------  ORDER SUMMARY : FAMILY ----------------" << RESET << endl;
    famorder.printOrder();
    famorder.checkOut();

    cout << BOLD << GREEN << "\n---------------- CHECKOUT -----------------" << RESET << endl;
    famorder.printOrder();
    famorder.pay();

    cout << BOLD << YELLOW << "\n---------------- PAYMENT COMPLETE  ----------------" << RESET << endl;
    famorder.printOrder();

    cout << BOLD << BLUE << "\n----------------- THANK YOU!  -----------------" << RESET << endl;

    //regular
    cout << BOLD << BLUE << "\n----------------  ORDER SUMMARY : REGULAR ----------------" << RESET << endl;
    regorder.printOrder();
    regorder.checkOut();

    cout << BOLD << GREEN << "\n---------------- CHECKOUT -----------------" << RESET << endl;
    regorder.printOrder();
    regorder.pay();

    cout << BOLD << YELLOW << "\n---------------- PAYMENT COMPLETE  ----------------" << RESET << endl;
    regorder.printOrder();

    cout << BOLD << BLUE << "\n----------------- THANK YOU!  -----------------" << RESET << endl;




    delete jessica;
    delete alex;
    //for website
    delete myWeb;
    delete myweb2;
    return 0;
}
