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
