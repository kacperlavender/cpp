#include "gtest/gtest.h"
#include "matlab.hpp"

TEST(MatlabVectorTest, VectorAddition) {
    const std::size_t size = 3;
    int v1[] = {1, 2, 3};
    int v2[] = {4, 5, 6};

    int* result = add_vectors(v1, v2, size);
    ASSERT_NE(result, nullptr);

    EXPECT_EQ(result[0], 5);
    EXPECT_EQ(result[1], 7);
    EXPECT_EQ(result[2], 9);

    delete[] result;
}

TEST(MatlabVectorTest, EmptyVectorAddition) {
    int* result = add_vectors(nullptr, nullptr, 0);
    EXPECT_EQ(result, nullptr);
}

TEST(MatVectClassTest, ConstructorAndSize) {
    const std::size_t size = 5;
    MatVect vec(size);

    EXPECT_EQ(vec.size(), size);
}

TEST(MatVectClassTest, ElementAccess) {
    MatVect vec(3);
    vec.set_elem(0, 10);
    vec.set_elem(1, 20);
    vec.set_elem(2, 30);

    EXPECT_EQ(vec.get_elem(0), 10);
    EXPECT_EQ(vec.get_elem(1), 20);
    EXPECT_EQ(vec.get_elem(2), 30);
}

TEST(MatVectClassTest, NormCalculation) {
    MatVect vec(3);
    vec.set_elem(0, 3);
    vec.set_elem(1, 4);
    vec.set_elem(2, 0);

    EXPECT_DOUBLE_EQ(vec.norm(), 5.0);
}

TEST(MatVectClassTest, BoundaryCheck) {
    MatVect vec(3);

    EXPECT_THROW(vec.get_elem(3), std::out_of_range);
    EXPECT_THROW(vec.set_elem(3, 0), std::out_of_range);
}

TEST(PrintTest, VectorPrinting) {
    int v[] = {1, 2, 3};
    testing::internal::CaptureStdout();
    print_vector(v, 3);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 ");
}