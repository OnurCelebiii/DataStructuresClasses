#include "LinkedList.h"
#include <iostream>
#include <memory>

int main() {
  LinkedList<int> myList;

  myList.push_back(1);
  myList.push_back(2);

  return 0;
}
