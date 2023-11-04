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

///////////////////////////// deleteLast /////////////////////////////
// Test case for deleteLast
TYPED_TEST(LinkedListTest, DeleteLastOnNonEmptyList)
{
    // Setup a list with some elements
    this->list.push_back(1);
    this->list.push_back(2);
    this->list.push_back(3);

    // Delete the last element
    this->list.deleteLast();

    // Check if the size is reduced by 1
    EXPECT_EQ(this->list.getSize(), 2);

    // Check if the last element is now 2 instead of 3
    EXPECT_EQ(this->list.search(3), false);
}

// Test case for deleteLast on an empty list
TYPED_TEST(LinkedListTest, DeleteLastOnEmptyList)
{
    // Attempt to delete the last element on an empty list
    this->list.deleteLast();

    // Check if the list is still empty
    EXPECT_EQ(this->list.getSize(), 0);

    // Check if the list is empty as expected
    EXPECT_TRUE(this->list.isEmpty());
}

///////////////////////////// getSize /////////////////////////////
TYPED_TEST(LinkedListTest, IsEmptyOnCreation) { EXPECT_EQ(this->list.getSize(), 0); }

TYPED_TEST(LinkedListTest, IsOneAfterAddingOneElement)
{
    this->list.push_back(1);
    EXPECT_EQ(this->list.getSize(), 1);
}

TYPED_TEST(LinkedListTest, IsCorrectAfterAddingMultipleElements)
{
    this->list.push_back(1);
    this->list.push_back(2);
    EXPECT_EQ(this->list.getSize(), 2);
}

TYPED_TEST(LinkedListTest, IsCorrectAfterRemovingElements)
{
    this->list.push_back(1);
    this->list.push_back(2);
    this->list.deleteLast();
    EXPECT_EQ(this->list.getSize(), 1);
}

TYPED_TEST(LinkedListTest, IsZeroAfterRemovingAllElements)
{
    this->list.push_back(1);
    this->list.deleteLast();
    EXPECT_EQ(this->list.getSize(), 0);
}

/////////////////////// insertAfterIndex //////////////////////////
TYPED_TEST(LinkedListTest, InsertAfterIndex_EmptyList)
{
    this->list.insertAfterIndex(TypeParam{}, 1);
    EXPECT_EQ(this->list.getSize(), 1);
}

TYPED_TEST(LinkedListTest, InsertAfterIndex_AtBeginning)
{
    this->list.push_back(TypeParam{});
    this->list.insertAfterIndex(TypeParam{}, 1);
    EXPECT_EQ(this->list.getSize(), 2);
}

TYPED_TEST(LinkedListTest, InsertAfterIndex_AtEnd)
{
    this->list.push_back(TypeParam{});
    this->list.insertAfterIndex(TypeParam{}, this->list.getSize());
    EXPECT_EQ(this->list.getSize(), 2);
}

TYPED_TEST(LinkedListTest, InsertAfterIndex_InMiddle)
{
    this->list.push_back(TypeParam{});
    this->list.push_back(TypeParam{});
    this->list.insertAfterIndex(TypeParam{}, 1);
    EXPECT_EQ(this->list.getSize(), 3);
}

TYPED_TEST(LinkedListTest, InsertAfterIndex_InvalidNegativeIndex)
{
    this->list.push_back(TypeParam{});
    this->list.insertAfterIndex(TypeParam{}, -1);
    // Assuming the list size should remain unchanged.
    EXPECT_EQ(this->list.getSize(), 1);
}

TYPED_TEST(LinkedListTest, InsertAfterIndex_InvalidLargeIndex)
{
    this->list.push_back(TypeParam{});
    this->list.insertAfterIndex(TypeParam{}, this->list.getSize() + 2);
    // Assuming the list size should remain unchanged.
    EXPECT_EQ(this->list.getSize(), 1);
}

//////////////////////////// isEmpty /////////////////////////////
// Test case for isEmpty on an initially empty list
TYPED_TEST(LinkedListTest, IsEmptyOnEmptyList)
{
    // Check if the new list is empty
    EXPECT_TRUE(this->list.isEmpty());
}

// Test case for isEmpty on a list after adding elements
TYPED_TEST(LinkedListTest, IsEmptyAfterAddingElements)
{
    // Add an element to the list
    this->list.push_back(1);

    // Check if the list is not empty
    EXPECT_FALSE(this->list.isEmpty());
}

// Test case for isEmpty on a list after adding and removing elements
TYPED_TEST(LinkedListTest, IsEmptyAfterAddingAndRemovingElements)
{
    // Add an element to the list and then remove it
    this->list.push_back(1);
    this->list.deleteLast();

    // Check if the list is empty again
    EXPECT_TRUE(this->list.isEmpty());
}

///////////////////////////// search /////////////////////////////

TYPED_TEST(LinkedListTest, SearchInEmptyList) { EXPECT_FALSE(this->list.search(TypeParam{})); }

TYPED_TEST(LinkedListTest, SearchNonExistingSingleElement)
{
    this->list.push_back(TypeParam{});
    EXPECT_FALSE(this->list.search(TypeParam{} + 1));
}

TYPED_TEST(LinkedListTest, SearchExistingSingleElement)
{
    this->list.push_back(TypeParam{1});
    EXPECT_TRUE(this->list.search(TypeParam{1}));
}

TYPED_TEST(LinkedListTest, SearchExistingMultipleElements)
{
    this->list.push_back(TypeParam{1});
    this->list.push_back(TypeParam{2});
    this->list.push_back(TypeParam{3});
    EXPECT_TRUE(this->list.search(TypeParam{2}));
}

TYPED_TEST(LinkedListTest, SearchNonExistingMultipleElements)
{
    this->list.push_back(TypeParam{1});
    this->list.push_back(TypeParam{2});
    this->list.push_back(TypeParam{3});
    EXPECT_FALSE(this->list.search(TypeParam{4}));
}

using StdStringLinkedList = LinkedListTest<std::string>;

// Testing search for a character in a list of chars
TEST_F(StdStringLinkedList, SearchStdStringInList)
{
    LinkedList<std::string> list;
    list.push_back("Onur");
    list.push_back("Caner");
    list.push_back("Serdar");
    EXPECT_TRUE(list.search("Caner"));
    EXPECT_FALSE(list.search("Fuat"));
}

