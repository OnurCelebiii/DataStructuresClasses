#include "LinkedList.h"
#include <gtest/gtest.h>

// Test fixture for LinkedList tests
template <typename T> class LinkedListTest : public ::testing::Test
{
  protected:
    LinkedList<T> list;

    void SetUp() override
    {
        // You can set up initial conditions for all tests here if needed
    }

    void TearDown() override
    {
        // Clean up after each test case if needed
    }
};

using MyTypes = ::testing::Types<char, int, double>; // Add more types if needed
TYPED_TEST_SUITE(LinkedListTest, MyTypes);

#include "deleteLastTests.cpp"
#include "getSizeTests.cpp"
#include "isEmptyTests.cpp"
#include "searchTests.cpp"
#include "insertAfterIndexTests.cpp"

// Main function to run all tests
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
