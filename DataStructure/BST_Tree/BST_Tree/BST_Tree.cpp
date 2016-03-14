#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <string>
#include <math.h>
using namespace std;



class node
{
public:
	node* lChild;
	node* rChild;
	int value;
	node(){}
	node(int value){ this->value = value; lChild = rChild = NULL; }
};

class tree
{
public:
	queue<string> queue;
	node* root;
	tree(){ root = NULL; }
	void insert(int);
	void search(int);
	void Delete(int);
	void inorder();
	void preorder();
	void postorder();
};
void tree::insert(int n)
{
	if (root == NULL)
		root = new node(n);
	else
	{
		node* p = root;
		node* q=p;
		while (true)
		{
			if (p == NULL)
			{
				p = new node(n);
				if (n > q->value)
					q->rChild = p;
				else if (n < q->value)
					q->lChild = p;
				return;
			}
			else
			{
				q = p;
				if (n > p->value)
					p = p->rChild;
				else if (n < p->value)
					p = p->lChild;
				else if (n == p->value)
					return;
			}
		}
	}
}

void tree::search(int n)
{
	node* p = root;
	while (p != NULL)
	{
		if (n == p->value)
		{
			cout << "OK" << endl;
			return;
		}
		else if (n > p->value)
			p = p->rChild;
		else if (n < p->value)
			p = p->lChild;
	}
	if (p == NULL)
		cout << "NO" << endl;
}

void tree::Delete(int n)
{
	node* currentnode = root;
	node* prevcurrentnode = NULL;
	while (currentnode != NULL && currentnode->value != n)
	{
		prevcurrentnode = currentnode;
		if (n > currentnode->value)
			currentnode = currentnode->rChild;
		else if (n < currentnode->value)
			currentnode = currentnode->lChild;
		if (currentnode->value == n)
		{

		}
	}
	if (currentnode != NULL &&currentnode->value == n)
	{
		if (currentnode->lChild == NULL && currentnode->rChild == NULL)
		{
			if (prevcurrentnode != NULL)
			{
				if (n > prevcurrentnode->value)
					prevcurrentnode->rChild = NULL;
				else if (n < prevcurrentnode->value)
					prevcurrentnode->lChild = NULL;
				delete currentnode;
			}
			else
			{
				root = NULL;
				delete currentnode;
			}
		}
		else if (currentnode->lChild == NULL && currentnode->rChild != NULL)
		{
			if (prevcurrentnode != NULL)
			{
				if (n > prevcurrentnode->value)
					prevcurrentnode->rChild = currentnode->rChild;
				else if (n < prevcurrentnode->value)
					prevcurrentnode->lChild = currentnode->rChild;
				delete currentnode;
			}
			else
			{
				root = root->rChild;
				delete currentnode;
			}
		}
		else if (currentnode->lChild != NULL && currentnode->rChild == NULL)
		{
			if (prevcurrentnode != NULL)
			{
				if (n > prevcurrentnode->value)
					prevcurrentnode->rChild = currentnode->lChild;
				else if (n < prevcurrentnode->value)
					prevcurrentnode->lChild = currentnode->lChild;
				delete currentnode;
			}
			else
			{
				root = root->lChild;
				delete currentnode;
			}
		}
		else if (currentnode->lChild != NULL && currentnode->rChild != NULL)
		{
			node* p = currentnode->lChild;
			node* q = currentnode;
			node* r = q;
			bool flag = false;
			while (p->rChild != NULL)
			{
				q = p;
				flag = true;
				p = p->rChild;
			}
			int val = p->value;
			currentnode->value = val;
			if (p->lChild != NULL && flag == true)
				q->rChild = p->lChild;
			else if (p->lChild != NULL && flag == false)
				q->lChild = p->lChild;
			else if (p->lChild == NULL && flag == true)
				q->rChild = NULL;
			else if (p->lChild == NULL && flag == false)
				q->lChild = NULL;
			delete p;
		}
	}
	else
		return;
}

void tree::inorder()
{
	node* p = root;
	vector<int> ans;
	stack<node*> s;
	
	while (true)
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->lChild;
		}
		if (!s.empty())
		{
			ans.push_back(s.top()->value);
			p = s.top();
			s.pop();
			p = p->rChild;
		}
		else break;
	}
	string sss = "";

	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << " ";
	}
	cout << endl;
	delete p;
}

void tree::preorder()
{
	node* p = root;
	vector<int> ans;
	stack<node*> s;

	while (true)
	{
		while (p != NULL)
		{
			s.push(p);
			ans.push_back(p->value);
			p = p->lChild;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->rChild;
		}
		else break;
	}
	string sss = "";
	int j = 0;
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i != ans.size() - 1)
			cout << " ";
	}
	cout << endl;
	//queue.push(sss);
	delete p;
}

void tree::postorder()
{
	node* p = root;
	vector<int> ans;
	stack<node*> s;

	while (true)
	{
		while (p != NULL)
		{
			s.push(p);
			ans.push_back(p->value);
			p = p->rChild;
		}
		if (!s.empty())
		{
			p = s.top();
			s.pop();
			p = p->lChild;
		}
		else break;
	}
	string sss = "";
	for (int i = ans.size()-1; i >=0; i--)
	{
		cout << ans[i];
		if (i != 0)
			cout << " ";
	}
	cout << endl;
	delete p;
}

int main()
{
	tree* t = new tree();
	int n;
	int x;
	cin >> n;
	string ss = "";
	string sss = "";
	for (int i = 0; i < n; i++)
	{
		cin >> ss;
		if (ss == "Insert" || ss == "insert")
		{
			cin >> x;
			t->insert(x);
		}
		else if (ss == "Search" || ss == "search")
		{
			cin >> x;
			t->search(x);
		}
		else if (ss == "Print" || ss == "print")
		{
			cin >> sss;
			if (t->root != NULL)
			{
				if (sss == "In" || sss == "in")
					t->inorder();
				else if (sss == "Post" || sss == "post")
					t->postorder();
				else if (sss == "Pre" || sss == "pre")
					t->preorder();
			}
		}
		else if (ss == "Delete" || ss == "delete")
		{
			cin >> x;
			t->Delete(x);
		}
	}

	return 0;
}
