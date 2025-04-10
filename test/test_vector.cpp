#include "gtest/gtest.h"
#include "matlab.hpp"
#include <vector>
#include <stdexcept>

TEST(MatVectClassTest, ConstructorAndSize) {
    const std::size_t size = 5;
    MatVect vec(size);

    EXPECT_EQ(vec.size(), size);
    for (size_t i = 0; i < size; ++i) {
        EXPECT_EQ(vec.get_elem(i), 0);
    }
}

TEST(MatVectClassTest, VectorConstructor) {
    std::vector<int> vec_data = {1, 2, 3, 4, 5};
    MatVect vec(vec_data);

    EXPECT_EQ(vec.size(), 5);
    for (size_t i = 0; i < vec.size(); ++i) {
        EXPECT_EQ(vec.get_elem(i), vec_data[i]);
    }
}

TEST(MatVectClassTest, CopyConstructor) {
    MatVect vec1({1, 2, 3});
    MatVect vec2(vec1);

    EXPECT_EQ(vec1.size(), vec2.size());
    for (size_t i = 0; i < vec1.size(); ++i) {
        EXPECT_EQ(vec1.get_elem(i), vec2.get_elem(i));
    }
}

TEST(MatVectClassTest, SetElemTest) {
    MatVect vec(3);
    vec.set_elem(0, 10);
    vec.set_elem(1, 20);
    vec.set_elem(2, 30);

    EXPECT_EQ(vec.get_elem(0), 10);
    EXPECT_EQ(vec.get_elem(1), 20);
    EXPECT_EQ(vec.get_elem(2), 30);
}

TEST(MatVectClassTest, ToString) {
    MatVect vec({1, 2, 3});
    EXPECT_EQ(vec.to_string({1, 2, 3}), "1 2 3 ");

    MatVect empty_vec({});
    EXPECT_EQ(empty_vec.to_string({}), "");
}

TEST(MatVectClassTest, IteratorTest) {
    MatVect vec({1, 2, 3, 4, 5});
    std::vector<int> expected_values = {1, 2, 3, 4, 5};
    size_t i = 0;

    for (auto it = vec.begin(); it != vec.end(); ++it) {
        EXPECT_EQ(*it, expected_values[i++]);
    }
}

TEST(MatVectClassTest, ConstIteratorTest) {
    const MatVect vec({1, 2, 3, 4, 5});
    std::vector<int> expected_values = {1, 2, 3, 4, 5};
    size_t i = 0;

    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
        EXPECT_EQ(*it, expected_values[i++]);
    }
}

TEST(MatVectClassTest, AddVectorsTest) {
    MatVect vec1({1, 2, 3});
    MatVect vec2({4, 5, 6});

    std::vector<int> result = add_vectors(vec1, vec2);
    std::vector<int> expected_result = {5, 7, 9};

    EXPECT_EQ(result, expected_result);
}

TEST(MatVectClassTest, AddVectorsDifferentSizeTest) {
    MatVect vec1({1, 2, 3});
    MatVect vec2({4, 5});

    EXPECT_EQ(add_vectors(vec1, vec2), std::vector<int>()); // lub rzuć wyjątek
}

TEST(MatVectClassTest, NormCalculation) {
    MatVect vec(3);
    vec.set_elem(0, 3);
    vec.set_elem(1, 4);
    vec.set_elem(2, 0);

    EXPECT_DOUBLE_EQ(vec.norm(), 5.0);
}

TEST(MatVectClassTest, OutOfRangeTest) {
    MatVect vec(3);

    EXPECT_THROW(vec.get_elem(3), std::out_of_range);
    EXPECT_THROW(vec.set_elem(3, 10), std::out_of_range);
}