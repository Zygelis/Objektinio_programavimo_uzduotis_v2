#include "headers/my_lib.h"
#include "headers/deklaravimai.h"
#include <gtest/gtest.h>

// g++ -c ivestis.cpp -o ivestis.o
// g++ -c test_mediana.cpp -o test_mediana.o
// g++ -c funkcijos.cpp -o funkcijos.o
// g++ -o runTests test_mediana.o funkcijos.o ivestis.o -lgtest -lgtest_main -pthread
// ./runTests

TEST(MedianTest, OddSizeVector) {
    vector<int> values = {3, 1, 4, 1, 5};
    EXPECT_EQ(mediana(values), 3);
}

TEST(MedianTest, EvenSizeVector) {
    vector<int> values = {3, 1, 4, 1, 5, 9};
    EXPECT_EQ(mediana(values), 3.5);
}

TEST(MedianTest, SingleValueVector) {
    vector<int> values = {42};
    EXPECT_EQ(mediana(values), 42);
}

TEST(MedianTest, EmptyVector) {
    vector<int> values;
    EXPECT_THROW(mediana(values), std::invalid_argument);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}