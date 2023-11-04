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
