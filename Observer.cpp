#include <iostream>
using namespace std;
class Observer {
public:
    virtual void update(string message) = 0;
    virtual ~Observer() {}
};
