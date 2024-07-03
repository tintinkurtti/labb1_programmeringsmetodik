/**
 * Labb 1, dt047g HT2023
 * @author tiku2200@student.miun.se
 * @date 2023-09-17
 * @brief .h fil för klassen int_buffer
 */

#ifndef LABB1_INT_BUFFER_H
#define LABB1_INT_BUFFER_H

#include <algorithm>
#include <cstdlib>

class int_buffer {
public:
    explicit int_buffer(size_t size); // size_t is defined in cstdlib
    int_buffer(const int* source, size_t size);
    int_buffer(const int_buffer& rhs); // copy construct
    int_buffer(int_buffer &&rhs); // move construct
    int_buffer & operator=(const int_buffer& rhs); // copy assign
    int_buffer & operator=(int_buffer&& rhs); // move assign
    int& operator[](size_t index);
    const int& operator[](size_t index) const;
    size_t size() const;
    int* begin();
    int* end();
    const int* begin() const;
    const int* end() const;
    ~int_buffer() ;
private:
    int* first;
    int* last;
    void swap(int_buffer& int_buffer);
};


#endif //LABB1_INT_BUFFER_H
