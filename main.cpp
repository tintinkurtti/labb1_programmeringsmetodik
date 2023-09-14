#include <iostream>
#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buf){

    int j = 0;
    for (int* i = buf.begin(); i != buf.end(); i++){
        j++;
        *i = j;
    }

    for (const int* i = buf.begin(); i != buf.end(); i++){
        std::cout << *i << ", ";

    }
}


int main() {



    int_buffer b(10);

    f(b);

    return 0;
}
