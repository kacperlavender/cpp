#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_
#include <cstddef>
#include <iostream>

int* add_vectors(int* v1, int* v2, std::size_t n);

void print_vector(int* v, std::size_t n);

class MatVect {
    int * v_;
    std::size_t size_;

public:
    MatVect(std::size_t n);

    void get_elem(std::size_t pos) const;

    void set_elem(std::size_t pos, int val);

    std::size_t size() const;

    double norm() const;

};

#endif /* INCLUDE_MATLAB_HPP_ */