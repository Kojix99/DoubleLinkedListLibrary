#include <iostream>
#include "clsDbLinkedList.h"

using namespace std;

struct Node
{
	int Value;
	Node* next;
	Node* previous;
};

int main()
{
	clsDbLinkedList<int> MyDbLinkedList;

	MyDbLinkedList.InsertAtBeginning(5);
	MyDbLinkedList.InsertAtBeginning(4);
	MyDbLinkedList.InsertAtBeginning(3);
	MyDbLinkedList.InsertAtBeginning(2);
	MyDbLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List Content:\n";
	MyDbLinkedList.PrintList();

	MyDbLinkedList.InsertAfter(99, 400);

	cout << "\nLinked List After Insert:\n";
	MyDbLinkedList.PrintList();

	cout << "\n\n";
	MyDbLinkedList.GetItem(100);
}