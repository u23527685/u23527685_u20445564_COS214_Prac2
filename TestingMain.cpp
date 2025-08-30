#include "PizzaMenu.h"
#include "SpecialsMenu.h"
#include "Customer.h"
#include "Pizza.h"
#include <iostream>

int main()
{
    // Create menus
    PizzaMenu pizzaMenu;
    SpecialsMenu specialsMenu;

    // Create customers (observers)
    Customer *jessica = new Customer("Jessica");
    Customer *alex = new Customer("Alex");

    // Add observers to menus
    pizzaMenu.addObserver(jessica);
    pizzaMenu.addObserver(alex);
    specialsMenu.addObserver(jessica);

    // Create pizzas
    // Pizza *margherita = new Pizza("Margherita", 80.0);
    // Pizza *pepperoni = new Pizza("Pepperoni", 95.0);

    // Add pizzas
    // pizzaMenu.addPizza(margherita);
    // pizzaMenu.addPizza(pepperoni);

    // // Remove a pizza
    // pizzaMenu.removePizza(margherita);

    // Specials menu update
    specialsMenu.notifyObservers("Weekend Special: Buy 1 Get 1 Free!");

    // // Clean up
    // delete margherita;
    // delete pepperoni;
    delete jessica;
    delete alex;

    return 0;
}
