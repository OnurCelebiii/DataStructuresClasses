TYPED_TEST(LinkedListTest, SearchInEmptyList) {
    EXPECT_FALSE(this->list.search(TypeParam{}));
}

TYPED_TEST(LinkedListTest, SearchNonExistingSingleElement) {
    this->list.push_back(TypeParam{});
    EXPECT_FALSE(this->list.search(TypeParam{} + 1));
}

TYPED_TEST(LinkedListTest, SearchExistingSingleElement) {
    this->list.push_back(TypeParam{1});
    EXPECT_TRUE(this->list.search(TypeParam{1}));
}

TYPED_TEST(LinkedListTest, SearchExistingMultipleElements) {
    this->list.push_back(TypeParam{1});
    this->list.push_back(TypeParam{2});
    this->list.push_back(TypeParam{3});
    EXPECT_TRUE(this->list.search(TypeParam{2}));
}

TYPED_TEST(LinkedListTest, SearchNonExistingMultipleElements) {
    this->list.push_back(TypeParam{1});
    this->list.push_back(TypeParam{2});
    this->list.push_back(TypeParam{3});
    EXPECT_FALSE(this->list.search(TypeParam{4}));
}

using StdStringLinkedList = LinkedListTest<std::string>;

// Testing search for a character in a list of chars
TEST_F(StdStringLinkedList, SearchStdStringInList) {
    LinkedList<std::string> list;
    list.push_back("Onur");
    list.push_back("Caner");
    list.push_back("Serdar");
    EXPECT_TRUE(list.search("Caner"));
    EXPECT_FALSE(list.search("Fuat"));
}



