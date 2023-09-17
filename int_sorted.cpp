//
// Created by tinti on 2023-09-14.
//


#include "int_sorted.h"
#include "int_buffer.h"

int_sorted sort(const int* begin, const int* end){
    if (begin == end){return int_sorted(nullptr, 0);}
    if (begin == end -1) {return int_sorted(begin, 1);}
    ptrdiff_t half = (end-begin)/2; //pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

int_sorted::int_sorted ( const int * source , size_t size ) : buf(size){
    if(size <= 1){return;}
    *this = sort(begin(),end());
}

size_t int_sorted::size () const {
    return buf.size();
}

void int_sorted::insert ( int value ) {

    int_sorted new_val(&value, 1);
    buf = merge(new_val).buf;

}

const int* int_sorted::begin () const {
    return buf.begin();
}

const int* int_sorted::end () const {
    return buf.end();
}

int_sorted int_sorted::merge ( const int_sorted &merge_with ) const {

    const int* this_ptr = begin();
    const int* merge_ptr = merge_with.begin();
    int_buffer result(size() + merge_with.size());

    int index = 0;
    // Slå samman buffrarna i rätt ordning
    while (this_ptr != end() && merge_ptr != merge_with.end()) {

        if (*this_ptr < *merge_ptr) {
            result[index++] = *this_ptr++;
        } else {
            result[index++] = *merge_ptr++;
        }
    }

    // Lägg till kvarvarande element från båda buffrarna (om det finns några)
    while (this_ptr != end()) {
        result[index++] = *this_ptr++;
    }

    while (merge_ptr != merge_with.end()) {
        result[index++] = *merge_ptr++;
    }

    int_sorted finish(nullptr, 0);
    finish.buf = result;

    return finish;
}


