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
