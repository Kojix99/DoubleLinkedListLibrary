# 📚 clsDbLinkedList – Generic Doubly Linked List Library

### 🧑‍💻 Author
**Sohail Zoraibi**

### 📅 Completed On
**July 12, 2025**

---

## 📘 Overview

`clsDbLinkedList` is a reusable, template-based **doubly linked list** library for C++14.  
It supports any data type and provides all essential linked list operations, including:

- Insertion (at beginning, end, or after a node/index)
- Deletion (by node, value, first, or last)
- Searching for nodes
- Access and update by index
- In-place reversal and clearing
- Printing the list

This library is designed for educational purposes, manual memory management, and learning C++ data structures.  
All operations are implemented with clarity and safety in mind.

---

## 🗂️ File Structure

| File Name              | Description                                         |
|------------------------|-----------------------------------------------------|
| `clsDbLinkedList.h`    | Header file containing the template class and all operations |
| `main.cpp` (example)   | Example file to demonstrate usage and test the library |
| `README.md`            | This documentation file                             |

---

## 🛠️ Features and Functions

| Function                        | Description                                      |
|----------------------------------|--------------------------------------------------|
| `InsertAtBeginning`              | Insert a node at the start of the list           |
| `InsertAtEnd`                    | Insert a node at the end of the list             |
| `InsertAfter(Node*, T)`          | Insert after a given node                        |
| `InsertAfter(int, T)`            | Insert after a given index                       |
| `DeleteNode(Node*)`              | Delete a node by pointer                         |
| `DeleteNode(T)`                  | Delete a node by value                           |
| `DeleteFirstNode`                | Delete the first node                            |
| `DeleteLastNode`                 | Delete the last node                             |
| `Find`                           | Search for a node by value                       |
| `GetNode`                        | Get a node by index                              |
| `GetItem`                        | Get a value by index                             |
| `UpdateItem`                     | Update a value by index                          |
| `PrintList`                      | Print the entire list                            |
| `Clear`                          | Remove all nodes                                 |
| `Reverse`                        | Reverse the list in-place                        |
| `Size`                           | Get the number of nodes in the list              |
| `IsEmpty`                        | Check if the list is empty                       |

---

## ⏳ Development Timeline

| Date       | Task                                | Status   |
|------------|-------------------------------------|----------|
| 2025-07-05 | Project started                     | ✅ Done  |
| 2025-07-06 | Core insert/delete/search methods   | ✅ Done  |
| 2025-07-07 | Index-based access and update       | ✅ Done  |
| 2025-07-08 | Reverse and clear methods           | ✅ Done  |
| 2025-07-12 | Final review and documentation      | ✅ Done  |

---

## 📌 Usage Example
'''Cpp

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
