#include <gtest/gtest.h>
#include "LinkedList.h"

TEST(OnurTest, isEmpty_false)
{
    LinkedList<int> myList;

    myList.push_back(1);
    myList.push_back(2);

    ASSERT_EQ(false, myList.isEmpty());
}


TEST(OnurTest, isEmpty_true)
{
    LinkedList<int> myList;

    myList.push_back(1);
    myList.deleteFirst();
    myList.deleteFirst();
    
    ASSERT_EQ(true, myList.isEmpty());
}


int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
