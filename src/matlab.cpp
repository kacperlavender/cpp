#include "matlab.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>

std::vector<int> add_vectors(MatVect& v1, MatVect& v2) {
    std::vector<int> result(v1.size());
    std::transform(v1.begin(), v1.end(), v2.begin(), result.begin(), std::plus<int>());
    return result;
}


void print_vector(int* v, std::size_t n) {
    for (std::size_t i = 0; i < n; i++) {
        std::cout << v[i] << " ";
    }
}

MatVect::MatVect(std::size_t n) : v_(n, 0), size_(n) {}

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

    for (int it : v_) {
        sum += it * it;
    }
    return std::sqrt(sum);
}

std::string MatVect::to_string(const std::vector<int> v) const{
    std::string v_str;

    for (auto it : v) {
        v_str += std::to_string(it) + " ";
    }

    return v_str;
}