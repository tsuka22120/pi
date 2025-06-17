#include "num.h"
#include <iostream>


int main(){
    num n,m;
    n.setValue(123456789);
    m = n;
    std::cout << "n: " << n << std::endl;
    std::cout << "m: " << m << std::endl;
}