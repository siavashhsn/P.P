#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


int p_in_s(char c)
{
	switch (c)
	{
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '!': return 0;
	case '(': return 0;
	default: break;
	}
	return 0;
}
int p_out_s(char c)
{
	switch (c)
	{
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '!': return 3;
	case '(': return 3;
	case ')': return 0;
	}
	return -1;
}
string infix2postfix(string s)
{
	stack<char> stack;
	string postfix = "";

	for (size_t i = 0; i < s.length(); i++)
	{
		if ((s[i] >= 'A' && s[i] <= 'z'))
			postfix += s[i];
		else if (s[i] == '!' && s[i + 1] >= 'A' && s[i + 1] <= 'z')
		{
			postfix += s[i + 1];
			postfix += s[i];
			i++;
		}
		else
		{
			if (stack.empty())
				stack.push(s[i]);
			else
			{
				if (p_out_s(s[i]) > p_in_s(stack.top()))
					stack.push(s[i]);
				else
				{
					if (s[i] == ')')
					{
						while (stack.top() != '(')
						{
							postfix += stack.top();
							stack.pop();
						}
						stack.pop();
						if (!stack.empty() && stack.top() == '!')
						{
							postfix += stack.top();
							stack.pop();
						}
					}
					else
					{
						while (!stack.empty() && p_out_s(s[i]) <= p_in_s(stack.top()))
						{
							postfix += stack.top();
							stack.pop();
						}
						stack.push(s[i]);
					}
				}
			}
		}
	}
	while (!stack.empty())
	{
		postfix += stack.top();
		stack.pop();
	}

	return postfix;
}

class node
{
	char value;
	node* lChild;
	node* rChild;
public:
	node(){ lChild = rChild = NULL; value = NULL; }
	node(node* lChild, char value, node* rChild)
	{
		this->lChild = lChild;
		this->value = value;
		this->rChild = rChild;
	}
	node* get_lChild(){ return lChild; }
	char get_value(){ return value; }
	node* get_rChild(){ return rChild; }
	void set_lChild(node* x){ lChild = x; }
	void set_value(int x){ value = x; }
	void set_rChild(node* x){ rChild = x; }
};

class  tree
{
	node* root=NULL;
	queue < node* > queue;
public:
	 tree();
	 void biuld(char c);
	 void biuld2(char x, string s);
};

void tree::biuld(char c)
{
	bool leftchild = false;
	bool rightchild = false;
	node* n = new node(NULL, c, NULL);

	if (root == NULL)
	{
		root = n;
		queue.push(n);
	}
	else
	{
		if (queue.front()->get_lChild() == NULL)
		{
			queue.front()->set_lChild(n);
			if (!(c >= 'A' && c <= 'z'))
				queue.push(n);
			leftchild = true;
		}
		else if (queue.front()->get_rChild() == NULL)
		{
			queue.front()->set_rChild(n);
			if (!(c >= 'A' && c <= 'z'))
				queue.push(n);
			if (leftchild == true)
			{
				queue.pop();
				leftchild = false;
			}
		}
	}
}
void tree::biuld2(char x, string s)
{
	node* p;
	node* n;
	if (s=="")
	{
		n = new node(NULL, x, NULL);
		root = n;
	}
	else
	{

		p = root;
		int counter = 0;
		while (counter != s.length())
		{
			if (s[counter] == 'r' || s[counter] == 'R')
			{
				if (p != NULL && counter != s.length())
				{
					p = p->get_rChild();
					counter++;
				}
				else
					break;
			}
			else if (s[counter] == 'l' || s[counter] == 'L')
			{
				if (p != NULL && counter != s.length())
				{
					p = p->get_lChild();
					counter++;
				}
				else
					break;
			}
		}
		if (p == NULL && counter == s.length())
		{
			n = new node(NULL, x, NULL);
			p = n;
			cout << "accepted" << endl;
		}
		else
			cout << "wrong node" << endl;
	}
}

int main()
{
	tree* a = new tree();
	a->biuld2('1', "");
	a->biuld2('2', "rr");
	a->biuld2('3', "r");
	a->biuld2('4', "l");
	a->biuld2('5', "ll");

	cout << infix2postfix("!(!(!(!a+!b))*!((!c/!d)/!(!e-!f)))");

	return 0;
}
