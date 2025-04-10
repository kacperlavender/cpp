#ifndef INCLUDE_MATLAB_HPP_
#define INCLUDE_MATLAB_HPP_
#include <cstddef>
#include <iostream>
#include <vector>

class MatVect {
    std::vector<int> v_;
    std::size_t size_;

public:
    MatVect(std::size_t n);
    MatVect(const std::vector<int>& v) : v_(v), size_(v.size()) {} // Dodano inicjalizację size_


    void get_elem(std::size_t pos) const;

    void set_elem(std::size_t pos, int val);

    std::size_t size() const;

    double norm() const;

    std::string to_string(std::vector<int> v) const;

    std::vector<int>::iterator begin() { return v_.begin(); }

    std::vector<int>::iterator end() { return v_.end(); }

    std::vector<int>::const_iterator cbegin() const { return v_.cbegin(); }

    std::vector<int>::const_iterator cend() const { return v_.cend(); }
};

std::vector<int> add_vectors(MatVect& v1, MatVect& v2);


#endif /* INCLUDE_MATLAB_HPP_ */