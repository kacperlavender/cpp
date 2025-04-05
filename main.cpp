#include "matlab.hpp"
#include <iostream>

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int* c = add_vectors(a, b, 3);
    print_vector(c, 3);

    MatVect vec(3);
    vec.set_elem(0, 10);
    vec.set_elem(1, 20);
    vec.set_elem(2, 30);

    std::cout << "\nNorma wektora: " << vec.norm() << std::endl;

    delete [] c;
    return 0;
}