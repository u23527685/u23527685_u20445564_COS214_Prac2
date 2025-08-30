#include "OrderState.h"
#include "CheckOut.h"
#include "Paid.h"

using namespace std;

OrderState::OrderState(){
    
}

OrderState* OrderState::checkout(){
    return new CheckOut();
}

OrderState* OrderState::pay(){
    return new Paid(tip);
}