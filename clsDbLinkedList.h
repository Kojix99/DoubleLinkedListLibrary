// ============================================================================
//  clsDbLinkedList - Generic Doubly Linked List Library (C++14)
//  Author       : Sohail Zoraibi
//  Completed On : 07/12/2025
//  Description  :
//      clsDbLinkedList is a reusable, template-based doubly linked list library
//      for C++. It supports any data type and provides essential linked list
//      operations, including insertion, deletion, searching, reversing, and more.
//      The library is designed for educational purposes, manual memory management,
//      and learning C++ data structures. All operations are implemented with
//      clarity and safety in mind, making this library ideal for students and
//      anyone interested in understanding how linked lists work under the hood.
//
//      Key Features:
//        - Generic (template) support for any data type
//        - Insert, delete, and search operations
//        - Access and update by index
//        - In-place reversal and list clearing
//        - Manual memory management (no STL containers)
//        - Simple, readable code for learning and extension
// ============================================================================

#pragma once

using namespace std;

template <class T>

class clsDbLinkedList
{
private:
	int _Size = 0;

public:

	class Node
	{
	public:
		T Value;
		Node* next;
		Node* previous;
	};

	Node* head = nullptr;

	void InsertAtBeginning(T Value)
	{
		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->next = head;
		NewNode->previous = nullptr;

		if (head != nullptr)
			head->previous = NewNode;

		head = NewNode;
		_Size++;
	}

	void PrintList()
	{
		Node* Current = head;
		while (Current != nullptr)
		{
			cout << Current->Value << " ";
			Current = Current->next;
		}
		cout << "\n";
	}

	Node* Find(T Value)
	{
		Node* Current = head;
		while (Current != nullptr)
		{
			if (Current->Value == Value)
			{
				return Current;
			}
			Current = Current->next;
		}
		return nullptr;
	}

	void InsertAfter(Node* Current, T Value)
	{
		if (Current == nullptr) return;

		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->next = Current->next;
		NewNode->previous = Current;

		if (Current->next != nullptr)
			Current->next->previous = NewNode;

		Current->next = NewNode;
		_Size++;
	}

	void InsertAtEnd(T Value)
	{
		Node* NewNode = new Node;
		NewNode->Value = Value;
		NewNode->next = nullptr;

		if (head == nullptr)
		{
			NewNode->previous = nullptr;
			head = NewNode;
		}
		else
		{
			Node* Current = head;
			while (Current->next != nullptr)
			{
				Current = Current->next;
			}

			Current->next = NewNode;
			NewNode->previous = Current;
		}
		_Size++;
	}

	void DeleteNode(Node* NodeToDelete)
	{
		if (NodeToDelete == nullptr || head == nullptr) return;

		if (NodeToDelete == head)
		{
			head = head->next;
			if(head != nullptr)
				head->previous == nullptr;
		}

		if (NodeToDelete->previous != nullptr)
		{
			NodeToDelete->previous->next = NodeToDelete->next;
		}

		if (NodeToDelete->next != nullptr)
			NodeToDelete->next->previous = NodeToDelete->previous;
		
		delete NodeToDelete;

		_Size--;
	}

	void DeleteNode(int Value)
	{
		Node* NodeToDelete = Find(Value);
		DeleteNode(NodeToDelete);
	}

	void DeleteFirstNode()
	{
		if (head == nullptr) return;
		
		Node* FirstNode = head;
		head = head->next;
		if (head != nullptr)
			head->previous = nullptr;

		delete FirstNode;

		_Size--;
	}

	void DeleteLastNode()
	{
		if (head == nullptr) return;

		if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
			_Size--;
			return;
		}

		Node* Current = head;
		
		while (Current->next != nullptr)
		{
			Current = Current->next;
		}

		Current->previous->next = nullptr;

		delete Current;

		_Size--;
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return _Size == 0;
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		Node* temp = nullptr;
		Node* Current = head;

		while (Current != nullptr)
		{
			temp = Current->previous;
			Current->previous = Current->next;
			Current->next = temp;
			Current = Current->previous;
		}

		if(temp != nullptr)
			head = temp->previous;
	}

	Node* GetNode(int Index)
	{
		if (Index < 0 || Index >= _Size) return nullptr;

		int Counter = 0;
		Node* Current = head;
		while (Current->next != nullptr)
		{
			if (Counter == Index)
				break;
			Current = Current->next;
			Counter++;
		}

		return Current;
	}

	T GetItem(int Index)
	{
		Node* NodeIndex = GetNode(Index);
		if (NodeIndex == nullptr) return T();

		return NodeIndex->Value;
	}

	bool UpdateItem(int Index, T NewValue)
	{
		Node* NodeIndex = GetNode(Index);

		if (NodeIndex != nullptr)
		{
			NodeIndex->Value = NewValue;
			return true;
		}
		return false;
	}

	bool InsertAfter(int Index, T NewNodeValue)
	{
		Node* CurrentNode = GetNode(Index);

		if (CurrentNode != nullptr)
		{
			InsertAfter(CurrentNode, NewNodeValue);
			return true;
		}
		return false;
	}
};