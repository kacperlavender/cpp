#include "matlab.hpp"
#include <iostream>
#include <vector>

int main() {
    MatVect vect1({1, 2, 3});
    MatVect vect2({4, 5, 6});

    std::vector<int> result = add_vectors(vect1, vect2);

    std::cout << "Suma wektorów: ";
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    MatVect vec(3);
    vec.set_elem(0, 10);
    vec.set_elem(1, 20);
    vec.set_elem(2, 30);

    std::cout << "\nNorma wektora: " << vec.norm() << std::endl;

    std::vector<int> my_vector = {1, 2, 3, 4, 5};
    MatVect vect_from_vector(my_vector);

    std::cout << "wektor jako tekst: " << vec.to_string(my_vector) << std::endl;

    MatVect vecto({2, 8, 3, 2, 5});

    std::cout << "Elementy vecto: ";
    for (auto it = vecto.begin(); it != vecto.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}