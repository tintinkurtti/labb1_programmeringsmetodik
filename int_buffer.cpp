//
// Created by tinti on 2023-08-31.
//

#include "int_buffer.h"


    int_buffer::int_buffer ( size_t size ){
    this->sz = size;
}
    int_buffer::int_buffer ( const int * source , size_t size ){


}
    int_buffer::int_buffer ( const int_buffer & rhs ) { // copy construct

}
    int_buffer::int_buffer ( int_buffer && rhs ) { // move construct

}
    int_buffer & int_buffer::operator =( const int_buffer & rhs ) { // copy assign

}
    int_buffer & int_buffer::operator =( int_buffer && rhs ) { // move assign

}
    int & int_buffer::operator []( size_t index ) {

}
    const int & int_buffer::operator []( size_t index ) const {

}
    size_t int_buffer::size () const {

}
    int * int_buffer::begin () {

}
    int * int_buffer::end () {

}
    const int * int_buffer::begin () const {

}
    const int * int_buffer::end () const {

}
    int_buffer::~ int_buffer () {

}
