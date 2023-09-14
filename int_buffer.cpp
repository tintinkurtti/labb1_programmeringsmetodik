//
// Created by tinti on 2023-08-31.
//

#include <algorithm>
#include "int_buffer.h"


int_buffer::int_buffer ( size_t size ): first(new int[size]), last(first + size){
}

int_buffer::int_buffer ( const int * source , size_t size ): int_buffer(size){
    std::copy(source, source + size, first);
}

int_buffer::int_buffer ( const int_buffer & rhs ): int_buffer(rhs.begin(), rhs.size()) { // copy construct
}

int_buffer::int_buffer ( int_buffer && rhs ): first(nullptr), last(nullptr) { // move construct
    swap(rhs);
}

int_buffer & int_buffer::operator =( const int_buffer & rhs ) { // copy assign
    int_buffer temp(rhs);
    swap(temp);
}

int_buffer & int_buffer::operator =( int_buffer && rhs ) { // move assign
    swap(rhs);
    return *this;
}

int & int_buffer::operator []( size_t index ) {
    return first[index];
}

const int & int_buffer::operator []( size_t index ) const {
    return first[index];
}

size_t int_buffer::size () const {
    return std::distance(first, last);
}

int * int_buffer::begin () {
    return first;
}

int * int_buffer::end () {
    return last;
}

const int * int_buffer::begin () const {
    return first;
}

const int * int_buffer::end () const {
    return last;
}

int_buffer::~ int_buffer () {
    delete []first;
}

void int_buffer::swap(int_buffer &int_buffer) {
    std::swap(first, int_buffer.first);
    std::swap(last, int_buffer.last);
}
