/**
 * Labb 1, dt047g HT2023
 * @author tiku2200@student.miun.se
 * @date 2023-09-17
 * @brief .h fil för klassen int_sorted
 */

#ifndef LABB1_INT_SORTED_H
#define LABB1_INT_SORTED_H

#include <algorithm>
#include <cstdlib>
#include "int_buffer.h"


class int_sorted {
private:
    int_buffer buf;
public :
    int_sorted(const int* source, size_t size);
    size_t size() const;
    void insert(int value);
    const int* begin() const;
    const int* end() const;
    int_sorted merge(const int_sorted& merge_with) const;
    int_sorted sort(const int* begin, const int* end);
};


#endif //LABB1_INT_SORTED_H
