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

void demo(){
    //creating a website
    Website* mySite = new Website("Roman Pizza Paradise");
    cout << BOLD << BLUE << "-----------------  WELCOME TO "<<mySite->getName()<<" -----------------" << RESET << endl << endl;

    ToppingGroup vegan("Vegetarian");
    vegan.add(new Onions());
    vegan.add(new Olives());
    vegan.add(new GreenPeppers());
    vegan.add(new Mushrooms());
    vegan.add(new Feta());

    ToppingGroup meat("Meat Lovers");
    meat.add(new Salami());
    meat.add(new BeefSausage());
    meat.add(new Cheese());
    meat.add(new Pepperoni());

    cout << BOLD << CYAN << "\nAvailable Pizzas with prices:" << RESET << endl;
    cout << vegan.getName() << " | R" << vegan.getPrice() << endl;
    cout << meat.getName() << " | R" << meat.getPrice() << endl;

    // base pizzas
    BasePizza veganBase(&vegan);
    BasePizza meatBase(&meat);

    //decorate pizza
    ExtraCheese veganCheesy(&veganBase);
    StuffedCrust meatStuffed(&meatBase);

    /*cout << BOLD << GREEN << "\nPizzas After Customization:" << RESET << endl;
    veganCheesy.printPizza();
    meatStuffed.printPizza();*/

    // Observers testing
    cout << BOLD << MAGENTA << "Adding to menu" << RESET << endl;
    PizzaMenu menu;
    Customer* jessica = new Customer("Jessica");

    menu.addObserver(jessica);
    menu.addObserver(mySite);
    menu.addPizza(&veganBase);
    menu.addPizza(&meatBase);
    menu.removePizza(&meatBase);
    menu.removeObserver(jessica);
    menu.addPizza(&meatBase);

    cout << BOLD << BLUE << "\nCreating an order" << RESET << endl;
    Order myOrder;
    myOrder.addPizza(&veganCheesy);
    myOrder.addPizza(&meatStuffed);

    cout << BOLD << YELLOW << "\n--- Order Summary ---" << RESET << endl;
    myOrder.printOrder();

    cout << BOLD << GREEN << "\nProceeding to Checkout..." << RESET << endl;
    myOrder.checkOut();

    cout << BOLD << BLUE << "\n---- PAYMENT SUCCESSFUL!----" << RESET << endl;
    myOrder.pay();

    cout << BOLD << GREEN << "\nThank you for ordering from"<<mySite->getName() << RESET << endl;
    
    
    delete jessica;
    delete mySite;
}

void test(){

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
    cout << BOLD << GREEN << "\n---------------- CHECKOUT -----------------" << RESET << endl;
    order.checkOut();

    cout << BOLD << YELLOW << "\n---------------- PAYMENT COMPLETE  ----------------" << RESET << endl;
    order.pay();


    cout << BOLD << BLUE << "\n----------------- THANK YOU!  -----------------" << RESET << endl;

    //family
    cout << BOLD << BLUE << "\n----------------  ORDER SUMMARY : FAMILY ----------------" << RESET << endl;
    famorder.printOrder();

    cout << BOLD << GREEN << "\n---------------- CHECKOUT -----------------" << RESET << endl;
    famorder.checkOut();
   
    cout << BOLD << YELLOW << "\n---------------- PAYMENT COMPLETE  ----------------" << RESET << endl;
    famorder.pay();

    cout << BOLD << BLUE << "\n----------------- THANK YOU!  -----------------" << RESET << endl;

    //regular
    cout << BOLD << BLUE << "\n----------------  ORDER SUMMARY : REGULAR ----------------" << RESET << endl;
    regorder.printOrder();
    

    cout << BOLD << GREEN << "\n---------------- CHECKOUT -----------------" << RESET << endl;
    regorder.checkOut();
    

    cout << BOLD << YELLOW << "\n---------------- PAYMENT COMPLETE  ----------------" << RESET << endl;
    regorder.pay();


    cout << BOLD << BLUE << "\n----------------- THANK YOU!  -----------------" << RESET << endl;




    delete jessica;
    delete alex;
    //for website
    delete myWeb;
    delete myweb2;

}

int main() {

    demo();
    //test();

    return 0;
}
