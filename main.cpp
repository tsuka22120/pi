#include "num.h"
#include <iostream>


int main(){
    num n;
    n.setValue(123456789);
    n.print(); // Should print "+ 123456789"
    
    n.setValue(-987654321);
    n.print(); // Should print "- 987654321"
    
    n.setValue(0);
    n.print(); // Should print "0"
    
    return 0;
}