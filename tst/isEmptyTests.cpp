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