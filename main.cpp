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

void f_range(int_buffer buf){

    int j = 0;
    for (int &e: buf){
        j++;
        e = j;
    }

    for (const int e: buf){
        std::cout << e << ", ";
    }
}


int main() {

    f(int_buffer(10)); //test för buffern

    std::cout << std::endl;

    f_range(int_buffer(10)); // test för range-for insättning

    std::cout << std::endl;

    int_sorted test_buf(nullptr, 0);

    for (int i = 0; i <= 100; i++){
        test_buf.insert(rand());
    }
    for (const int* i = test_buf.begin(); i != test_buf.end(); i++){
        std::cout << *i << ", ";
    }


    return 0;

}
