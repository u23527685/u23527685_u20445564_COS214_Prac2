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
    cout << BOLD << BLUE << "-----------------  WELCOME TO PIZZA PARADISE  -----------------" << RESET << endl << endl;

    ToppingGroup vegan("Vegeterian");
    ToppingGroup meat("Meat Lovers");

    // Vegan pizza
    vegan.add(new Onions());
    vegan.add(new GreenPeppers());
    vegan.add(new Mushrooms());
    vegan.add(new Feta());

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
    specialsMenu.addObserver(jessica);
    specialsMenu.notifyObservers("Weekend Special: Buy 1 Get 1 Free!");

    // Base pizzas
    BasePizza b1(&meat);
    BasePizza b2(&meatdel);

    // Decorators
    StuffedCrust sc(&b1);
    ExtraCheese ec(&b2);
    StuffedCrust dd(&ec);

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

    cout << BOLD << BLUE << "\n----------------  ORDER SUMMARY ----------------" << RESET << endl;
    order.printOrder();
    order.checkOut();

    cout << BOLD << GREEN << "\n---------------- CHECKOUT -----------------" << RESET << endl;
    order.printOrder();
    order.pay();

    cout << BOLD << YELLOW << "\n---------------- PAYMENT COMPLETE  ----------------" << RESET << endl;
    order.printOrder();

    cout << BOLD << BLUE << "\n----------------- THANK YOU!  -----------------" << RESET << endl;

    delete jessica;
    delete alex;

    return 0;
}
