#include "stdafx.h"
#include <conio.h>
#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
	}

};

class LinkList
{
private:
	Node* first;
	Node* last;
	int size;
public:
	LinkList() { first = last = NULL, size = 0; }

	bool AddFirst(int x)
	{
		Node* temp = new Node(x);
		if (first == NULL)
		{
			first = temp;
			last = temp;
			this->size++;
		}
		else
		{
			temp->next = first;
			first = temp;
			this->size++;
		}
		return true;
	}

	bool AddLast(int x)
	{
		Node* temp = new Node(x);
		if (last == NULL)
		{
			first = temp;
			last = temp;
			this->size++;
		}
		else
		{
			last->next = temp;
			last = temp;
			this->size++;
		}
		return true;
	}

	bool AddMiddle(int x, int pos)
	{
		if (pos == 0)
			AddFirst(x);
		else if (pos == this->size)
			AddLast(x);
		else if (pos > 0 && pos < this->size)
		{
			Node* p = first;
			Node* temp = new Node(x);
			int counter = 0;
			while (counter != pos - 1)
			{
				p = p->next;
				counter++;
			}
			temp->next = p->next;
			p->next = temp;
			this->size++;
			return true;
		}
		else
			return false;
	}

	bool DeleteFirst(int& x)
	{
		if (first == NULL) return false;

		Node* t = first;

		if (first == last)
			first = last = NULL;
		else
			first = first->next;
		x = t->data;
		delete t;
		this->size--;

		return true;
	}

	bool DeleteLast(int& x)
	{
		if (last == NULL) return false;

		Node* t = last;
		Node* p = first;
		if (first == last)
			last=first = NULL;
		else
			while (p->next != last)
				p = p->next;
		x = t->data;
		last = p;
		last->next = NULL;
		delete t;
		this->size--;

		return true;
	}

	bool DeleteMiddle(int& x, int pos)
	{
		if (pos == 0)
			DeleteFirst(x);
		else if (pos == this->size)
			DeleteLast(x);
		else if (pos > 0 && pos < this->size)
		{
			Node* p = first;
			Node* t;
			int counter = 0;
			while (counter != pos - 1)
			{
				p = p->next;
				counter++;
			}
			x = p->next->data;
			t = p->next;
			p->next = p->next->next;
			delete t;
			this->size--;

			return true;
		}
		else return false;
	}

	bool GetFirst(int& x) 
	{
		if (first == NULL) return false;
		else x = first->data;
		return true; 
	}
	bool GetLast(int& x) 
	{
		if (last == NULL) return false;
		else x = last->data;
		return true; 
	}
	bool GetMiddle(int& x , int pos) 
	{
		if (pos == 0) GetFirst(x);
		else if (pos == size) GetLast(x);
		else if (pos > 0 && pos < size)
		{
			Node* p = first;
			int counter = 0;
			while (p->next != NULL)
			{
				if (counter == pos)
				{
					x = p->data;
					break;
				}
				p = p->next;
				counter++;
			}
		}
		else return false;

		return true; 
	}

	int Getsize() { return size; }

	void Print()
	{
		Node* p = first;
		for (int i = 0; i< this->size; i++)
		{
			cout << p->data;
			if (i < this->size - 1)
				cout << " -> ";
			p = p->next;
		}
	}

	void Clean()
	{
		Node* p = first;
		while (first->next != NULL)
		{
			first = first->next;
			delete p;
			p = first;
		}
		first = last = NULL;
		delete p;
	}

	void Reverse()
	{
		Node* p = first;
		Node* q = NULL;
		Node* r = NULL;
		last = first;
		if (this->size != 1)
		{
			while (p != NULL)
			{
				r = q;
				q = p;
				p = p->next;
				q->next = r;
			}
			first = q;
		}
	}

	void Sort_n2()
	{
		if (size > 1)
		{
			Node* p = first;
			Node* q = first->next;
			this->AddFirst(0);
			this->AddLast(0);
			Node* r = first;
			Node* t = q->next;
			for (int i = 0; i < size - 3; i++)
			{
				r = first;
				p = first->next;
				q = p->next;
				t = q->next;
				for (int j = size - 4; j >= i; j--)
				{
					if (p->data > q->data)
					{
						r->next = q;
						q->next = p;
						p->next = t;
					}
					if (t != last)
					{
						r = r->next;
						p = r->next;
						q = p->next;
						t = t->next;
					}
				}
			}
		}
		int x;
		this->DeleteFirst(x);
		this->DeleteLast(x);
	}

	void Unique()
	{
		Node* q=first;
		Node* p=NULL;
		Node* r;
		while (q != NULL)
		{
			r = q;
			p = q->next;
			while (p != NULL)
			{
				if (p->data == q->data)
				{
					r->next = p->next;
					delete p;
					p = r->next;
					this->size--;
				}
				else
				{
					p = p->next;
					r = r->next;
				}
			}
			q = q->next;
		}
	}

	void Unique2()
	{
		Node* p = first;
		Node* q;
		if (first != NULL)
			while (p->next != NULL)
			{
				q = p->next;
				if (p->data == q->data)
				{
					p->next = p->next->next;
					delete q;
					size--;
				}
				else
					p = p->next;
			}
	}

};

int main()
{
	int n;
	LinkList* list = new LinkList();
	//list->AddFirst(2);
	//list->AddFirst(5);
	//list->AddLast(6);
	//list->AddMiddle(7, 2);
	list->AddLast(4);
	list->AddLast(4);
	list->AddLast(4);
	list->AddLast(1);
	list->AddLast(4);
	list->AddLast(4);
	list->AddLast(4);
	list->AddLast(1);
	list->Sort_n2();
	list->Print();
	list->Unique2();
	cout << endl;
	//list->Sort_n2();
	//list->DeleteMiddle(n, 2);
	//list->DeleteFirst(n);
	//list->DeleteLast(n);
	//list->Reverse();
	list->Print();
	_getch();
	return 0;
}