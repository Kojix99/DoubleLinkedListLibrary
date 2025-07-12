# clsDbLinkedList

A generic, doubly linked list library for C++.

---

**Author:** Sohail Zoraibi  
**Completed:** July 12, 2025

---

## Overview

`clsDbLinkedList` is a template-based, doubly linked list implementation in C++14. It supports any data type and provides essential linked list operations such as insertion, deletion, searching, reversing, and more. This library is ideal for learning data structures and C++ templates.

## Features

- Template-based: works with any data type.
- Insert at beginning, end, or after a specific node/index.
- Delete by node, value, first, or last node.
- Find nodes by value.
- Get node or item by index.
- Update item by index.
- Reverse the list in-place.
- Clear the entire list.
- Print the list contents.
- Check if the list is empty.
- Get the current size of the list.

## Usage Example
#include "clsDbLinkedList.h" #include <iostream>
int main() { clsDbLinkedList<int> list;
list.InsertAtBeginning(3);
list.InsertAtEnd(5);
list.InsertAtBeginning(1);

list.PrintList(); // Output: 1 3 5

list.DeleteNode(3);
list.PrintList(); // Output: 1 5

std::cout << "Size: " << list.Size() << std::endl; // Output: 2

list.Reverse();
list.PrintList(); // Output: 5 1

return 0;
}
