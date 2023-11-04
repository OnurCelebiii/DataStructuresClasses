#include <gtest/gtest.h>
#include <limits>
#include "Vector.h" // Include your Vector class header here

template <typename T>
class VectorTest : public ::testing::Test {
protected:
    Vector<T> vec;
};

using MyTypesVector = ::testing::Types<char, int, double, std::string>;
TYPED_TEST_SUITE(VectorTest, MyTypesVector);

TYPED_TEST(VectorTest, InitialSizeAndCapacity) {
    EXPECT_EQ(this->vec.get_index(), 0);
    EXPECT_EQ(this->vec.get_capacity(), 1);
}

TYPED_TEST(VectorTest, PushBackIncreasesSize) {
    this->vec.push_back(TypeParam());
    EXPECT_EQ(this->vec.get_index(), 1);
}

TYPED_TEST(VectorTest, PushFrontIncreasesSize) {
    this->vec.push_front(TypeParam());
    EXPECT_EQ(this->vec.get_index(), 1);
}

TYPED_TEST(VectorTest, PopBackDecreasesSize) {
    this->vec.push_back(TypeParam());
    this->vec.pop_back();
    EXPECT_EQ(this->vec.get_index(), 0);
}

TYPED_TEST(VectorTest, FindExistingElement) {
    TypeParam value = TypeParam();
    this->vec.push_back(value);
    EXPECT_TRUE(this->vec.isFind(value));
}

TYPED_TEST(VectorTest, DoNotFindNonExistingElement) {
    EXPECT_FALSE(this->vec.isFind(TypeParam()));
}

TYPED_TEST(VectorTest, GetValueAtIndex) {
    TypeParam value = TypeParam();
    this->vec.push_back(value);
    EXPECT_EQ(this->vec.getValueInIndex(0), value);
}

TYPED_TEST(VectorTest, GetFirstAndLastItems) {
    TypeParam firstValue = TypeParam();
    TypeParam lastValue = TypeParam();
    this->vec.push_back(firstValue);
    this->vec.push_back(lastValue);
    EXPECT_EQ(this->vec.getFirstItem(), firstValue);
    EXPECT_EQ(this->vec.getLastItem(), lastValue);
}

TYPED_TEST(VectorTest, InsertUsingIndex) {
    TypeParam value1 = TypeParam();
    TypeParam value2 = TypeParam();
    this->vec.push_back(value1);
    this->vec.insertUsingIndex(0, value2);
    EXPECT_EQ(this->vec.getValueInIndex(0), value2);
    EXPECT_EQ(this->vec.getValueInIndex(1), value1);
}

TYPED_TEST(VectorTest, DeleteSpecificIndex) {
    TypeParam value1 = TypeParam();
    TypeParam value2 = TypeParam();
    this->vec.push_back(value1);
    this->vec.push_back(value2);
    this->vec.deleteSpesificIndex(0);
    EXPECT_EQ(this->vec.getValueInIndex(0), value2);
}

TYPED_TEST(VectorTest, IndexOperator) {
    TypeParam value = TypeParam();
    this->vec.push_back(value);
    EXPECT_EQ(this->vec[0], value);
}

TYPED_TEST(VectorTest, IndexValueChange) {
    TypeParam value1 = TypeParam();
    TypeParam value2 = TypeParam();
    this->vec.push_back(value1);
    this->vec.indexValueChange(0) = value2;
    EXPECT_EQ(this->vec[0], value2);
}

TYPED_TEST(VectorTest, ClearVector) {
    this->vec.push_back(TypeParam());
    this->vec.clear_vector();
    EXPECT_EQ(this->vec.get_index(), 0);
    EXPECT_EQ(this->vec.get_capacity(), 1);
}

// The following test expects an exception to be thrown when an invalid index is accessed.
TYPED_TEST(VectorTest, IndexOutOfBounds) {
    EXPECT_THROW(this->vec[1], const char*);
}

