#ifndef WEBSITE_H
#define WEBSITE_H

#include "Observer.h"
#include <string>
using namespace std;

class Website : public Observer {
private:
    string websiteName;
    
public:
    Website();
    ~Website();
    
    void update(string message) override;
    string getWebsiteName();
};

#endif