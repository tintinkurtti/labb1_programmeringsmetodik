/**
 * Labb 1, dt047g HT2023
 * @author tiku2200@student.miun.se
 * @date 2023-09-17
 * @brief .cpp fil för klassen int_sorted
 */

#include "int_sorted.h"
#include "int_buffer.h"

int_sorted int_sorted::sort(const int* begin, const int* end){
    if (begin == end){return int_sorted(nullptr, 0);}
    if (begin == end -1) {return int_sorted(begin, 1);}
    ptrdiff_t half = (end-begin)/2; //pointer diff type
    const int* mid = begin + half;
    return sort(begin, mid).merge(sort(mid, end));
}

int_sorted::int_sorted(const int* source , size_t size): buf(source, size){
    if(size <= 1){return;}
    *this = sort(begin(),end());
}

size_t int_sorted::size() const{
    return std::distance(buf.begin(), end());
}

void int_sorted::insert(int value){
    int_sorted new_val(&value, 1);
    buf = merge(new_val).buf;
}

const int* int_sorted::begin() const{
    return buf.begin();
}

const int* int_sorted::end() const{
    return buf.end();
}

int_sorted int_sorted::merge(const int_sorted& merge_with) const{
    const int* this_ptr = begin();
    const int* merge_ptr = merge_with.begin();

    int_buffer result(size() + merge_with.size());
    int *result_ptr = result.begin();

    while (this_ptr != end() && merge_ptr != merge_with.end()) {

        if (*this_ptr < *merge_ptr) {
            *result_ptr++ = *this_ptr++;
        } else {
            *result_ptr++ = *merge_ptr++;
        }
    }

    while (this_ptr != end()) {
        *result_ptr++ = *this_ptr++;
    }

    while (merge_ptr != merge_with.end()) {
        *result_ptr++ = *merge_ptr++;
    }

    int_sorted finish(nullptr, 0);
    finish.buf = result;

    return finish;
}


