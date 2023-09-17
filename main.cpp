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

    int_sorted test_buf1(nullptr, 0);

    for (int i = 0; i <= 100; i++){
        test_buf1.insert(rand());
    }
    for (const int* i = test_buf1.begin(); i != test_buf1.end(); i++){
        std::cout << *i << ", ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    int_sorted test_buf2(nullptr, 0);

    for (int i = 0; i <= 100; i++){
        test_buf2.insert(rand());
    }
    for (const int* i = test_buf2.begin(); i != test_buf2.end(); i++){
        std::cout << *i << ", ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    int_sorted fin = test_buf1.merge(test_buf2);

    for (const int* i = fin.begin(); i != fin.end(); i++){
    std::cout << *i << ", ";
    }

    std::cout << std::endl;
    std::cout << std::endl;

    int_buffer a(10);

    int j = 0;
    for (int &e: a){
        j++;
        e = j;
    }

    int_buffer b(a.begin(), 5);

    int_buffer c(b);

    c[3] = 2;

    int_buffer d = c;

    d[4] = 1;

    for (auto e : d){
        std::cout << e << ", ";
    }



    return 0;

}
