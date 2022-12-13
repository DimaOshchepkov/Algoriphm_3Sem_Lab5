#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
struct Node
{
	Node<T>* next;
	T value;
	Node<T>* prev;

	Node(T value = -1, Node* next = nullptr, Node* prev = nullptr) : next(next), prev(prev), value(value) {};
};

template <typename T>
class List
{
private:
	Node<T>* begin;
	Node<T>* end;
	int size;

public:
	List()
	{
		begin = new Node<T>();
		end = begin;
		size = 0;
	}
	/*
	List(const List& other)
	{
		this->begin = new Node<T>();
		this->end = begin;
		this->size = 0;
		for (Node<T>* ptr = other.begin; ptr != other.end; ptr = ptr->next)
			this->PushBack(ptr->value);
	}*/
	/*
	~List()
	{
		if (size != 0)
		{
			for (Node<T>* sup = begin->next; sup != end; sup = sup->next)
				delete sup->prev;

		}
		delete end->prev;
		delete end;
	}*/

	void Clear()
	{
		if (size != 0)
		{
			for (Node<T>* sup = begin->next; sup != end; sup = sup->next)
				delete sup->prev;

			delete end->prev;
			begin = end;
			size = 0;
		}

	}

	List<T> Copy()
	{
		List<T> copy;
		for (Node<T>* ptr = begin; ptr != end; ptr = ptr->next)
			copy.PushBack(ptr->value);

		return copy;
	}

	void PushFront(T value)
	{
		Node<T>* sup = new Node<T>(value, begin, nullptr);
		begin->prev = sup;
		begin = sup;
		size++;
	}

	void PushBack(T value)
	{
		if (size != 0)
		{
			Node<T>* sup = new Node<T>(value, end, end->prev);
			end->prev->next = sup;
			end->prev = sup;
			size++;
		}
		else
		{
			PushFront(value);
		}
	}

	void PopFront()
	{
		if (size != 0)
		{
			Node<T>* sup = begin;
			begin = begin->next;
			begin->prev = nullptr;
			delete sup;
			size--;
		}
	}

	void PopBack()
	{
		if (size != 0)
		{
			Node<T>* sup = end->prev;
			end->prev = end->prev->prev;
			end->prev->prev->next = end;
			delete sup;
			size--;
		}
	}

	Node<T>* Erase(Node<T>* ptr)
	{

		if (size >= 1)
		{
			if (ptr == begin)
			{
				PopFront();
				return begin;
			}
			if (ptr == end)
			{
				PopBack();
				return end;
			}
			else
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				Node<T>* sup = ptr->next;
				delete ptr;

				return sup;
			}
		}
		else
		{
			PopFront();
			return begin;
		}
		size--;
	}

	Node<T>* Begin()
	{
		return begin;
	}
	Node<T>* End()
	{
		return end;
	}

	int Size()
	{
		return size;
	}
	
	T Front()
	{
		if (size > 0)
			return begin->value;

		return -1;
	}

	T Back()
	{
		if (size > 0)
			return end->prev->value;

		return -1;
	}
};


template<typename T>
std::ostream& operator<<(std::ostream& os, List<T>& list)
{
	for (Node<T>* b = list.Begin(); b != list.End(); b = b->next)
		os << b->value << ' ';
	os << '\n';
	return os;
};


std::vector<List<int>> ConvertMatrixFromAdjacency(const std::vector<std::vector<int>>& matrix);

std::vector<std::vector<int>> ConvertMatrixFromLink(std::vector<List<int>>& link);

void CreateMatrix(std::string path = "graph.txt");

std::vector<std::vector<int>> ReadMatrixFormFile(const std::string& path = "graph.txt");

std::vector<List<int>> MainTreeWigth(std::vector<List<int>>& link);

std::vector<List<int>> MainTreeHeight(std::vector<List<int>>& link);

template <class T>
struct NodeT
{
	T value;
	NodeT<T>* right;
	NodeT<T>* left;
	int count;

	NodeT(T value, NodeT<T>* left = nullptr, NodeT<T>* right = nullptr, int count = 0) :
		value(value), left(left), right(right), count(count) {};
};

template <class T>
class Tree
{
private:

	NodeT<T>* root;
	int size;

	void _AddRec(T& value, NodeT<T>*& ptr)
	{
		if (ptr == nullptr)
		{
			ptr = new NodeT<T>(value, nullptr, nullptr, 1);
			size++;
		}
		else
		{
			if (ptr->value > value)
				_AddRec(value, ptr->left);
			else if (ptr->value < value)
				_AddRec(value, ptr->right);
			else
				ptr->count++;
		}
	}

	int _CountOf(T& el, NodeT<T>* ptr)
	{
		if (ptr == nullptr)
			return -1;
		else if (ptr->value)
			return ptr->count;
		else if (el < ptr->value)
			return _CountOf(el, ptr->left);
		else if (el > ptr->value)
			return _CountOf(el, ptr->right);

		return -1;
	}

public:
	Tree(std::initializer_list<T> list = {})
		: root(nullptr), size(0)
	{
		for (T el : list)
			Add(el);
	}


	void Add(T& value)
	{
		_AddRec(value, root);
	}

	NodeT<T>* GetRoot()
	{
		return root;
	}

	int CountOf(T el)
	{
		return _CountOf(el, root);
	}
	
};

template <class T>
void PrintGraph(NodeT<T>* root, int shift = 0)
{
	if (root != nullptr)
	{
		PrintGraph(root->left, shift + 4);
		std::cout.width(shift);
		std::cout << root->value << std::endl;
		PrintGraph(root->right, shift + 4);
	}
};

template <class T>
void CountElement(NodeT<T>* root)
{
	if (root != nullptr)
	{
		std::cout << root->value << ": " << root->count << '\n';
		CountElement(root->left);
		CountElement(root->right);
	}
};
/*
template <class T>
bool Eqval(NodeT<T> t1, NodeT<T> t2)
{
	if (t1 != nullptr && t2 != nullptr)
	{
		if (t1->value == t2->value)
		{
			Eqval(t1->left, t2->left)
		}
	}
}
*/