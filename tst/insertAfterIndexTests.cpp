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