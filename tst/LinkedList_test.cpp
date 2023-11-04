#include "LinkedList.h"
#include <gtest/gtest.h>

TEST(isEmpty, false) {
  LinkedList<int> myList;

  myList.push_back(1);
  myList.push_back(2);

  ASSERT_EQ(false, myList.isEmpty());
}

TEST(isEmpty, true) {
  LinkedList<int> myList;

  myList.push_back(1);
  myList.deleteFirst();
  myList.deleteFirst();

  ASSERT_EQ(true, myList.isEmpty());
}

TEST(isEmpty, initial) {
  LinkedList<int> myList;

  ASSERT_EQ(true, myList.isEmpty());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
