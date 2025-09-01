#ifndef WEBSITE_H
#define WEBSITE_H

#include "Observer.h"
#include <string>
using namespace std;

class Website : public Observer {
private:
    string websiteName;
    
public:
    Website(string websiteName);
    ~Website();
    
    void update(string message) override;
    string getName() const override;
    virtual bool operator==(const Observer& other)const override;
    

};

#endif