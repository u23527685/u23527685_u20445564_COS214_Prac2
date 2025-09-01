#include "Website.h"
#include "Observer.h"
#include <iostream>

Website::Website() : websiteName("Romeo's Pizza Website") {
    cout << "Website system initialized." << endl;
}

Website::~Website() {
    cout << "Website system shutdown." << endl;
}

void Website::update(string message) {
    cout << "[WEBSITE UPDATE] " << message << endl;
    cout << "Website menu has been automatically updated!" << endl;
}

string Website::getName()
{
    return websiteName;
}
