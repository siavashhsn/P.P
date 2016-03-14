#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <math.h>
#include <Windows.h>
using namespace std;

int* push(int* a, int n);
int* pop(int* a);
static size_t size = 1;



int* push(int* a, int n)
{
	size_t i = 0;
	for (i = 0; i < size; i++)
	{
		if (a[i] == 0)
		{
			a[i] = n;
			i++;
			break;
		}
	}

	if (i == size)
	{
		size = 2 * i;
		int* b = new int[size];
		for (size_t k = 0; k < size; k++)
		{
			b[k] = NULL;
		}
		for (size_t j = 0; j < size / 2; j++)
		{
			b[j] = a[j];
		}
		return b;
	}
	return a;
}

int* pop(int* a)
{
	size_t i;
	for (i = 0; i < size; i++)
	{
		if (a[i] == NULL)
		{
			a[i - 1] = NULL;
		}
		else if (i == size - 1)
			a[i] = NULL;
	}
	size_t counter = 0;

	for (size_t j = 0; j < size; j++)
	{
		if (a[j] != NULL)
			counter++;
		else
			break;
	}
	if (size != 2)
	{
		if (size / counter == 4)
		{
			size = size / 2;
			int* b = new int[size];
			for (size_t k = 0; k < size; k++)
			{
				b[k] = NULL;
			}
			for (size_t h = 0; h < size; h++)
			{
				b[h] = a[h];
			}
			return b;
		}
	}
	else if (size == 2)
		if (counter == 0)
		{
			size = 1;
			int* b = new int[size];
			b[0] = NULL;
			return b;
		}
	return a;
}

class node
{
	int prev;
	int next;
	int value;
public:
	node(int prev, int value, int next)
	{
		this->next = next;
		this->value = value;
		this->prev = prev;
	}
	node(){}
	int get_value	()		{ return value; }
	int get_prev	()		{ return prev; }
	int get_next	()		{ return next; }
	void set_prev	(int x) { prev = x; }
	void set_value	(int x) { value = x; }
	void set_next	(int x) { next = x; }
};

class LinkList
{
	int arraylenght = 1;
	int next_prev = -1;
	int prev_next = -1;
	int index;
	int first;
	int last;
public:
	node** linklist;
	LinkList()
	{
		linklist = new node*[arraylenght];
		index = 0;
		first = -1;
		last = -1;
	}
	void pop(int pos);
	void push(int x, int pos);
	void print();

private:
	node** amplifierArray(node** x);
	void addFirst(int x);
	void addLast(int x);
	void addMiddle(int x, int pos);
	node** reducerArray(node** x);
	void deleteFirst();
	void deleteLast();
	void deleteMiddle(int pos);
};

node** LinkList::amplifierArray		(node** x)
{
	arraylenght *= 2;
	node** temp = new node*[arraylenght];
	for (int i = 0; i < arraylenght / 2; i++)
	{
		temp[i] = new node(linklist[i]->get_prev(), linklist[i]->get_value(), linklist[i]->get_next());
	}
	return temp;
}

void LinkList::addMiddle			(int x, int pos)
{
	int counter = 0;
	int prev__next = first;
	int next__prev;
	while (counter != pos)
	{
		next__prev = prev__next;
		prev__next = linklist[prev__next]->get_next();
		counter++;
	}
	linklist[index] = new node(next__prev, x, prev__next);
	linklist[prev__next]->set_prev(index);
	linklist[next__prev]->set_next(index);
	index++;
	if (index == arraylenght)
		linklist=amplifierArray(linklist);
}

void LinkList::addFirst			(int x)
{
	linklist[index] = new node(-1, x, first);
	if (first >= 0)
		linklist[first]->set_prev(index);
	first=index;
	if (index == 0)
		last = index;
	index++;
	if (index == arraylenght)
		linklist=amplifierArray(linklist);
}

void LinkList::addLast			(int x)
{
	linklist[index] = new node(last, x, -1);
	if (last >= 0)
		linklist[last]->set_next(index);
	if (index == 0)
		first = index;
	last = index;
	index++;
	if (index == arraylenght)
		linklist=amplifierArray(linklist);
}

void LinkList::push				(int x, int pos)
{
	if (pos == 0)
		addFirst(x);
	else if (pos == index)
		addLast(x);
	else if (pos > 0 && pos < index)
		addMiddle(x, pos);
	else
		cout << "wrong position." << endl;
}

node** LinkList::reducerArray(node** x)
{
	arraylenght = arraylenght / 2;
	node** temp = new node*[arraylenght];
	for (int i = 0; i < index; i++)
	{
		temp[i] = new node(linklist[i]->get_prev(), linklist[i]->get_value(), linklist[i]->get_next());
	}
	return temp;
}

void LinkList::deleteFirst()
{
	if (index == 0)
		cout << "Link List Is Empty." << endl;
	else if (index == 1)
	{
		//delete linklist[first];
		linklist[first]->set_prev(NULL);
		linklist[first]->set_next(NULL);
		linklist[first]->set_value(NULL);
		linklist = reducerArray(linklist);
		index--;
		first = -1;
		last = -1;
	}
	else if (index >= 2)
	{
		int newfirst = linklist[first]->get_next();
		linklist[linklist[first]->get_next()]->set_prev(-1);
		if (index - 1 != first)
		{
			linklist[first]->set_next(linklist[index - 1]->get_next());
			linklist[first]->set_prev(linklist[index - 1]->get_prev());
			linklist[first]->set_value(linklist[index - 1]->get_value());
			if (index-1 != newfirst)
				linklist[linklist[first]->get_prev()]->set_next(first);
			if (index - 1 != last)
				linklist[linklist[first]->get_next()]->set_prev(first);
			else
				last = first;
			delete linklist[index - 1];
		}
		else
		{
			//delete linklist[first];
			linklist[first]->set_prev(NULL);
			linklist[first]->set_next(NULL);
			linklist[first]->set_value(NULL);
		}

		if (index - 1 != newfirst)
			first = newfirst;
		index--;
	}
	if (index == arraylenght/4)
		linklist = reducerArray(linklist);
}

void LinkList::deleteLast()
{
	if (index == 0)
		cout << "Link List Is Empty." << endl;
	else if (index == 1)
	{
		//delete linklist[first];
		linklist[last]->set_prev(NULL);
		linklist[last]->set_next(NULL);
		linklist[last]->set_value(NULL);
		linklist = reducerArray(linklist);
		index--;
		first = -1;
		last = -1;
	}
	else if (index >= 2)
	{
		int newlast = linklist[last]->get_prev();
		linklist[linklist[last]->get_prev()]->set_next(-1);
		if (index - 1 != last)
		{
			linklist[last]->set_next(linklist[index - 1]->get_next());
			linklist[last]->set_prev(linklist[index - 1]->get_prev());
			linklist[last]->set_value(linklist[index - 1]->get_value());
			if (index - 1 != first)
				linklist[linklist[last]->get_prev()]->set_next(last);
			else
				first = last;
			if (index-1 != newlast)
				linklist[linklist[last]->get_next()]->set_prev(last);
			delete linklist[index - 1];
		}
		else
		{
			//delete linklist[first];
			linklist[last]->set_prev(NULL);
			linklist[last]->set_next(NULL);
			linklist[last]->set_value(NULL);
		}

		if (index -1 != newlast)
			last = newlast;
		index--;
		
	}
	if (index == arraylenght / 4)
		linklist = reducerArray(linklist);
}

void LinkList::deleteMiddle(int pos)
{
	int counter = 0;
	int posIndex=first;
	while (counter != pos)
	{
		posIndex = linklist[posIndex]->get_next();
		counter++;
	}
	linklist[linklist[posIndex]->get_prev()]->set_next(linklist[posIndex]->get_next());
	linklist[linklist[posIndex]->get_next()]->set_prev(linklist[posIndex]->get_prev());
	if (posIndex != index - 1)
	{
		linklist[posIndex]->set_next(linklist[index - 1]->get_next());
		linklist[posIndex]->set_prev(linklist[index - 1]->get_prev());
		linklist[posIndex]->set_value(linklist[index - 1]->get_value());
		if (index - 1 != last)
			linklist[linklist[posIndex]->get_next()]->set_prev(posIndex);
		else
			last = posIndex;
		if (index - 1 != first)
			linklist[linklist[posIndex]->get_prev()]->set_next(posIndex);
		else
			first = posIndex;
		delete linklist[index - 1];
	}
	else
	{
		delete linklist[posIndex];
	}
	index--;
	if (index == arraylenght / 4)
		linklist = reducerArray(linklist);
}

void LinkList::pop(int pos)
{
	if (pos == 0)
		deleteFirst();
	else if (pos == index-1)
		deleteLast();
	else if (pos > 0 && pos < index-1)
		deleteMiddle(pos);
	else
		cout << "position is na valide." << endl;
}

void LinkList::print()
{
	int p = first;
	for (int i = 0; i < index; i++)
	{
		cout << linklist[p]->get_value();
		if (i < index - 1)
			cout << " -> ";
		if (p!=last)
			p = linklist[p]->get_next();
	}
	if (index == 0)
		cout << "NULL" << endl;
	else
		cout << endl;
}

int main()
{
	string s;
	int* a = new int[size];
	a[0] = 0;
	int n;

	LinkList* l = new LinkList();
	/*l->push(1, 0);
	l->print();
	l->push(3, 1);
	l->print();
	l->push(4, 2);
	l->print();
	l->push(5, 3);
	l->print();
	l->push(2, 1);
	l->print();
	l->pop(2);
	l->print();
	l->pop(0);
	l->print();
	l->pop(1);
	l->print();
	l->pop(0);
	l->print();
	l->pop(0);
	l->print();*/
	//l->pop(1);
	//l->print();
	//l->pop(0);
	//l->print();
	l->push(1,0);
	l->print();
	l->push(2, 1);
	l->print();
	l->push(3, 2);
	l->print();
	l->push(4, 3);
	l->print();
	l->push(5, 4);
	l->print();
	l->push(9, 0);
	l->print();
	l->pop(0);
	l->print();
	l->pop(0);
	l->print();
	l->pop(3);
	l->print();
	l->push(8, 0);
	l->print();
	l->push(7, 0);
	l->print();
	l->pop(0);
	l->print();
	l->push(6, 3);
	l->print();
	l->pop(1);
	l->print();
	l->pop(1);
	l->print();




	cin >> s;
	while (s != "done")
	{
		if (s == "push")
		{
			cin >> n;
			a = push(a, n);
			for (size_t j = 0; j < size; j++)
			{
				cout << a[j];
				if (j != size - 1)
					cout << " -- ";
			}
		}
		if (s == "pop")
		{
			a = pop(a);
			for (size_t j = 0; j < size; j++)
			{
				cout << a[j];
				if (j != size - 1)
					cout << " -- ";
			}
		}
		cout << endl;
		cin >> s;
	}

	return 0;
}
