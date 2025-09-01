#include "Website.h"
#include "Observer.h"
#include <iostream>


Website::Website(string websiteName)
{
    this->websiteName = websiteName;
}

Website::~Website()
{
    cout << "Website system shutdown." << endl;
}

void Website::update(string message) {
    cout << "[WEBSITE UPDATE] " << message << endl;
    cout << "Website menu has been automatically updated!" << endl;
}

string Website::getName() const
{
    return websiteName;
}

bool Website::operator==(const Observer &other) const
{
    return (this->getName() == other.getName());
}
