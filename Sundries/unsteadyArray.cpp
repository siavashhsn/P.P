#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <array>
#include <math.h>
using namespace std;

int* push(int a[], int n);
int* pop(int* a);
static size_t size = 1;


int main()
{
	string s;
	int* a = new int[size];
	a[0] = NULL;
	int n;

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

int* push(int a[],int n)
{
	size_t i=0;
	for (i = 0; i < size ; i++)
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
		for (size_t j = 0; j < size/2; j++)
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

	for (size_t j = 0;  j < size;  j++)
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