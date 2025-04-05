#include "matlab.hpp"
#include <iostream>
#include <cmath>


int * add_vectors(int* v1, int* v2, std::size_t n) {
    auto * result = new int[n];

    for(std::size_t i = 0; i < n; i++) {
        result[i] = v1[i] + v2[i];
    }

    return result;
}

void print_vector(int* v, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
}

MatVect::MatVect(std::size_t n) : size_(n) {
    v_ = new int[n];
}

void MatVect::get_elem(std::size_t pos) const {
    std::cout << v_[pos] << std::endl;
}


std::size_t MatVect::size() const {
    return size_;
}

void MatVect::set_elem(std::size_t pos, int val) {
    v_[pos] = val;
}

double MatVect::norm() const {
    double sum = 0;
    for (std::size_t i = 0; i < size_; i++) {
        sum += v_[i] * v_[i];
    }
    return std::sqrt(sum);