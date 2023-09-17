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




    // int_buffer b(10);

    int_sorted a(nullptr, 0);

    int_sorted b(nullptr, 0);

    a.insert(5);
    a.insert(2);
    a.insert(1);

    b.insert(8);
    b.insert(3);
    b.insert(11);


    int_sorted c = b.merge(a);

    for (const int* i = c.begin(); i != c.end(); i++){
        std::cout << *i << ", ";
    }


    return 0;

}
