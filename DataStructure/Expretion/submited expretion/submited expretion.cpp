#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>

using namespace std;

class _node
{
public:
	int index;
	_node* next;
};

class node
{
	char value;
	node* lChild;
	node* rChild;
	node* parent;
	char TF;
	int index;
public:
	node(){ lChild = rChild = NULL; value = NULL; TF = NULL; }
	node(char value, char TF, int index)
	{
		this->value = value;
		this->TF = TF;
		this->index = index;
		lChild = rChild = parent = NULL;
	}

	node(char value, char TF)
	{
		this->value = value;
		this->TF = TF;
	}

	node* get_lChild(){ return lChild; }
	char get_value(){ return value; }
	node* get_rChild(){ return rChild; }
	char get_TF(){ return TF; }
	node* get_parent(){ return parent; }
	int get_Index(){ return index; }
	void set_lChild(node* x){ lChild = x; }
	void set_value(char x){ value = x; }
	void set_rChild(node* x){ rChild = x; }
	void set_parent(node* x){ parent = x; }
	void set_TF(char x){ TF = x; }
};
class  tree
{
public:
	vector<node*> vector1;
	int _counter = 0;
	node** array;
	_node* array2[28];
	pair<char, char> postArray[2500];
	tree()
	{
		for (int i = 0; i < 28; i++)
		{
			array2[i] = new _node();
		}
	};
	~tree(){
		for (int i = 1; i <= aL; i++)
		{
			delete array[i];
		}
		delete[] array;
		vector1.clear();
	}

	/////////////////

	void permutation(int);

	/////////////////

	string postorder();

	/////////////////

	char FT();

	/////////////////

	void biuld3(int, int, char);

	/////////////////

	int aL = 0;
	void set_Array_Length(int n)
	{
		array = new node*[n + 1];
		aL = n;
	}

	/////////////////

};

void tree::biuld3(int child, int parent, char whatchild)
{
	if (array[parent]->get_value() == '!')
	{
		array[parent]->set_rChild(array[child]);
		return;
	}
	if (whatchild == 'L')
		array[parent]->set_lChild(array[child]);
	else if (whatchild == 'R')
		array[parent]->set_rChild(array[child]);
	array[child]->set_parent(array[parent]);
}

/////////////////////////////////////////////////////////////////

void tree::permutation(int n)
{
	int l = (int)pow(2, (double)n);
	char* prevperm = new char[n];
	char* currentperm = new char[n];
	for (int j = 0; j < n; j++)
	{
		currentperm[j] = '0';
		prevperm[j] = '0';
	}
	int counter = 0;
	for (int i = 0; i < 28; i++)
	{
		if (array2[i] != NULL)
		{
			_node* p = array2[i]->next;
			while (p != NULL)
			{
				int qqq = p->index;
				if (prevperm[counter] == '0')
					postArray[p->index].second = 'T';
				else
					postArray[p->index].second = 'F';
				p = p->next;
			}
			counter++;
		}
	}
	counter = 0;
	char c = FT();
	if (c == 'T')
		_counter++;
	int x;
	for (int i = 1; i < l; i++)
	{
		x = 0;
		for (int j = n - 1; j >= 0; j--)
		{
			x += (int)prevperm[j] - 48 + 1;
			if (x == 1)
			{
				currentperm[j] = '1';
				for (int k = 0; k < j; k++)
				{
					currentperm[k] = prevperm[k];
				}
				break;
			}
			else
			{
				currentperm[j] = '0';
				x = 0;
			}
		}
		for (int i = 0; i < 28; i++)
		{
			if (array2[i] != NULL)
			{
				_node* p = array2[i]->next;
				while (p != NULL)
				{
					if (currentperm[counter] == '0')
						postArray[p->index].second = 'T';
					else
						postArray[p->index].second = 'F';
					p = p->next;
				}
				counter++;
			}
		}
		counter = 0;
		char c = FT();
		if (c == 'T')
			_counter++;
		for (int r = 0; r < n; r++)
		{
			prevperm[r] = currentperm[r];
			currentperm[r] = '0';
		}
	}
}
///////////////////////////////////////////////////////////

string tree::postorder()
{
	int ii = 0;
	string ans = "";
	stack<node*> s2;
	node* currentnode = array[1];
	while (true)
	{
		while (currentnode != NULL)
		{
			ans += currentnode->get_value();
			s2.push(currentnode);
			currentnode = currentnode->get_lChild();
		}
		if (!s2.empty())
		{
			currentnode = s2.top();
			s2.pop();
			currentnode = currentnode->get_rChild();
		}
		else
			break;
	}
	string ans_r = "";
	for (int w = ans.length() - 1; w >= 0; w--)
	{
		ans_r += ans[w];
	}
	return ans_r;
}

///////////////////////////////////////////////////////////

char tree::FT()
{
	vector<pair<char, char>> aa;
	int counter = 0;

	while (counter < aL)
	{
		if (postArray[counter].first == '&' || postArray[counter].first == '|' || postArray[counter].first == '!')
		{
			if (postArray[counter].first == '&')
			{
				counter++;
				char p = aa.back().second;
				aa.pop_back();
				char k = aa.back().second;
				aa.pop_back();
				if (p == 'T' && k == 'T')
				{
					p = 'T';
				}
				else
				{
					p = 'F';
				}
				aa.push_back(make_pair(p, p));
			}
			else if (postArray[counter].first == '|')
			{
				counter++;
				char p = aa.back().second;
				aa.pop_back();
				char k = aa.back().second;
				aa.pop_back();
				char t;
				if (p == 'F' && k == 'F')
				{
					t = 'F';
				}
				else
				{
					t = 'T';
				}
				aa.push_back(make_pair(t, t));
			}
			else if (postArray[counter].first == '!')
			{
				counter++;
				char k = aa.back().second;
				aa.pop_back();
				if (k == 'T')
				{
					k = 'F';
				}
				else
				{
					k = 'T';
				}
				aa.push_back(make_pair(k, k));
			}
		}
		else
		{
			aa.push_back(make_pair(postArray[counter].first, postArray[counter].second));
			counter++;
		}
	}
	char ans = aa.back().second;
	//for (size_t i = 0; i<aa.size(); i++) delete aa[i];
	return ans;
}
///////////////////////////////////////////////////////////


void biuldtree_W_p(string s)
{
	stack<node*> stack1;
	int i = 0;
	while (i != s.length())
	{
		if (s[i] >= 'A' && s[i] <= 'z')
		{
			node* p = new node(s[i], 'F');
			i++;
			stack1.push(p);
		}
		else
		{
			node* p = new node(s[i], 'F');
			if (s[i] != '!')
			{
				node* q = stack1.top();
				stack1.pop();
				node* r = stack1.top();
				stack1.pop();
				p->set_lChild(q);
				p->set_rChild(r);
			}
			else
			{
				node* q = stack1.top();
				stack1.pop();
				p->set_rChild(q);
			}
			stack1.push(p);
			i++;
		}
	}
}


int main()
{
	biuldtree_W_p("a!ab+*");
	tree* a = new tree();
	int n, m;
	cin >> n >> m;
	a->set_Array_Length(n);
	char c;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		if (c != 'T' && c != 'F')
			a->array[i] = new node(c, NULL, i);
		else
			a->array[i] = new node(c, c, i);
	}

	int child;
	int parent;
	char whatchild;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> child >> parent >> whatchild;
		a->biuld3(child, parent, whatchild);
	}



	if (n > 1)
	{
		string ss = a->postorder();
		for (size_t w = 0; w < ss.length(); w++)
		{
			if (ss[w] != 'T' && ss[w] != 'F')
			{
				if (ss[w] >= 'A' && ss[w] <= 'z' && ss[w] != 'T' && ss[w] != 'F')
				{
					int _index = (int)ss[w] - 97;
					_node* p = new _node();
					p->index = w;
					p->next = a->array2[_index]->next;
					a->array2[_index]->next = p;
				}
				a->postArray[w].first = ss[w];
			}
			else
			{
				a->postArray[w].first = ss[w];
				a->postArray[w].second = ss[w];
			}
		}
		a->permutation(m);
	}
	if (n == 1 && a->array[1]->get_value() >= 'A' && a->array[1]->get_value() <= 'z' && a->array[1]->get_value() != 'F')
		cout << a->_counter + 1;
	else if (n == 1 && a->array[1]->get_value() == 'F')
		cout << a->_counter;
	else
		cout << a->_counter;

	for (int i = 1; i <= a->aL; i++)
	{
		delete a->array[i];
	}
	delete[] a->array;
	a->vector1.clear();


	return 0;
}


