#include <iostream>
#pragma once 
using namespace std;

template <class T>
class clsDbLinkedList
{
public:
	class node
	{	
	public :
		T _value;
		node* _next;
		node* _prev;
		friend class clsDbLinkedList<T>;

		node()
		{

		}
		node(T value, node* next, node* prev)
		{
			_value = value;
			_next = next;
			_prev = prev;
		}
	};
	node* _head = NULL;
	int _Size = 0;

	void InsertAtBeginning(T value)
	{
		node* new_node = new node();
		new_node->_value = value;
		new_node->_prev = NULL;
		new_node->_next = _head;

		if (_head != NULL)
			_head->_prev = new_node;
		_head = new_node;

		_Size++;

	}

	void PrintList()
	{
		node* current = _head;
		while (current != NULL)
		{
			cout << current->_value << endl;
			current = current->_next;
		}
	}

	node* Find(T value)
	{
		node* current = _head;

		while (current != NULL)
		{
			if (current->_value == value)
				return current;
			current = current->_next;
		}
		return NULL;
	}

	void InsertAfter(node* CurrentNode, T value)
	{
		node* new_node = new node();


		if (CurrentNode == NULL)
			return;

		new_node->_value = value;
		new_node->_next = CurrentNode->_next;
		new_node->_prev = CurrentNode;

		if (CurrentNode->_next != NULL)
			CurrentNode->_next->_prev = new_node;

		CurrentNode->_next = new_node;
		_Size++;
	} 

	void InsertAtEnd(T value)
	{
		node* new_node = new node();
		node* current = _head;

		new_node->_value = value;
		new_node->_next = NULL;

		if (_head == NULL)
		{
			new_node->_prev = NULL;
			_head = new_node;
			_Size++;
			return;
		}

		while (current->_next != NULL)
			current = current->_next;

		new_node->_prev = current;
		current->_next = new_node;
		_Size++;
	}

	void DeleteNode(node* DeleteNode)
	{
		if (_head == NULL || DeleteNode== NULL)
			return;


		if (DeleteNode == _head)
		{
			_head = DeleteNode->_next;

			if (_head != NULL)
				_head->_prev = NULL;
			delete DeleteNode;
			_Size--;
			return;
		}

		if (DeleteNode->_next != NULL)
			DeleteNode->_next->_prev = DeleteNode->_prev;

		if (DeleteNode->_prev != NULL)
			DeleteNode->_prev->_next = DeleteNode->_next;

		delete DeleteNode;
		_Size--;
	}

	void DeleteFirstNode()
	{
		if (_head == NULL)
			return;

		node* current = _head;
		node* deleteNode = _head;


		_head = deleteNode->_next;
		
		if (_head != NULL)
			_head->_prev = NULL;

		_Size--;
		delete deleteNode;
	}

	void DeleteLastNode()
	{
		if (_head == NULL)
			return;

		if (_head->_next == NULL)
		{
			delete _head;
			_head = NULL;
			_Size--;
			return;
		}

		node* current = _head;

		while (current->_next -> _next != NULL)
			current = current->_next;

		node* temp = current->_next;
		current->_next = NULL;
		_Size--;
		delete temp;

	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0) ? true : false;
	}

	void Clear()
	{
		while (!IsEmpty())
			DeleteFirstNode();
	}

	void Reverse()
	{
		node* current = _head;
		node* temp = NULL;

		while (current != NULL)
		{
			temp = current->_prev;
			current->_prev = current->_next;
			current->_next = temp;
			current = current->_prev;
		}

		if (temp != NULL)
			_head = temp->_prev;
	}
	
	node* GetNode(int index)
	{
		int Count = 0;
		node* current = _head;

		if (_head == NULL)
			return NULL;

		if (index >= _Size || index < 0)
			return NULL;

		while (current != NULL && Count != index)
		{
			current = current->_next;
			Count++;
		}
		

		return current;
	}

	T GetItem(int index)
	{
		node* Item = GetNode(index);

		if (Item == NULL)
			return NULL;
		else
			return Item->_value;
		
	}

	bool UpdateItem(int Index, T value)
	{
		node* Update = GetNode(Index);
		
		if (Update != NULL)
		{
			Update->_value = value;
			return true;
		}
		return false;
	}

	bool InsertAfter(int Index, T Value)
	{
		node* currentItem = GetNode(Index);

		if (currentItem != NULL)
		{
			InsertAfter(currentItem, Value);
			return true;
		}
		
		return false;

	}
};