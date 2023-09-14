//
// Created by tinti on 2023-09-14.
//


#include "int_sorted.h"
#include "int_buffer.h"



int_sorted::int_sorted ( const int * source , size_t size ) : buf(size){
}

size_t int_sorted::size () const {
    return buf.size();
}

void int_sorted::insert ( int value ) {
    // Använd lower_bound för att hitta rätt plats att infoga värdet
    auto position = std::lower_bound(begin(), end(), value);

    // Infoga värdet vid den hittade positionen och öka bufferns storlek
    buf = int_buffer(buf.size() + 1);

    // Flytta alla element efter infogningspositionen ett steg åt höger
    for (auto it = end() - 1; it != position; --it) {
        *(it + 1) = *it;
    }

    // Sätt det nya värdet på infogningspositionen
    *position = value;

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
    int_sorted result;

    // Slå samman buffrarna i rätt ordning
    while (this_ptr != end() && merge_ptr != merge_with.end()) {
        if (*this_ptr < *merge_ptr) {
            result.insert(*this_ptr);
            ++this_ptr;
        } else {
            result.insert(*merge_ptr);
            ++merge_ptr;
        }
    }

    // Lägg till kvarvarande element från båda buffrarna (om det finns några)
    while (this_ptr != end()) {
        result.insert(*this_ptr);
        ++this_ptr;
    }

    while (merge_ptr != merge_with.end()) {
        result.insert(*merge_ptr);
        ++merge_ptr;
    }

    return result;
}
