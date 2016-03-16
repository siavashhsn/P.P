#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <math.h>
#include <vector>

using namespace std;

//////////////////////////////////////////////////
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
//////////////////////////////////////////////////
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
	/*~node()
	{
		delete rChild;
		delete lChild;
		TF = '\0';
		delete parent;
		index=NULL;
	}*/

	node* get_lChild(){ return lChild; }
	char get_value(){ return value; }
	node* get_rChild(){ return rChild; }
	char get_TF(){ return TF; }
	int get_Index(){ return index; }
	void set_lChild(node* x){ lChild = x; }
	void set_value(int x){ value = x; }
	void set_rChild(node* x){ rChild = x; }
	void set_parent(node* x){ parent = x; }
	void set_TF(char x){ TF = x; }
};
class  tree
{
	//node* root = NULL;
	//bool leftchild = false;
public:
	vector<node*> vector1;
	int _counter = 0;
	node** array;
	tree() {};
	~tree(){
		for (int i = 1; i <= aL; i++)
		{
			delete array[i];
		}
		delete[] array;
		vector1.clear();
	}

	/////////////////

	void biuld(char);

	/////////////////

	void biuld2(char, string);

	/////////////////

	void permutation(int,string);

	string* permutation2(int,string);

	/////////////////

	string postorder();

	/////////////////

	char FT(string, char*);

	/////////////////

	void biuld3(int, int, char);

	/////////////////

	int aL=0;
	void set_Array_Length(int n){ array = new node*[n + 1]; aL = n; }

	/////////////////

	void print(node*);

	/////////////////

};

////////////////////////////biuld_1///////////////////////////////

//void tree::biuld(char c)
//{
//	node* n = new node(NULL, c, NULL);
//
//	if (root == NULL)
//	{
//		root = n;
//		queue1.push(n);
//	}
//	else
//	{
//		if (queue1.front()->get_lChild() == NULL && leftchild == false)
//		{
//			if (queue1.front()->get_value() >= 'A' && queue1.front()->get_value() <= 'z')
//			{
//				leftchild = true;
//				return;
//			}
//			if (c != '0')
//			{
//				queue1.front()->set_lChild(n);
//				leftchild = true;
//			}
//			else
//			{
//				leftchild = true;
//				return;
//			}
//			if (c >= 'A' && c <= 'z')
//			{
//				vector1.push_back(n);
//				queue1.push(n);
//			}
//			else
//				queue1.push(n);
//		}
//		else if (queue1.front()->get_rChild() == NULL && leftchild == true)
//		{
//			if (queue1.front()->get_value() >= 'A' && queue1.front()->get_value() <= 'z')
//			{
//				leftchild = false;
//				queue1.pop();
//				return;
//			}
//			if (c != '0')
//			{
//				queue1.front()->set_rChild(n);
//				leftchild = false;
//				queue1.pop();
//			}
//			else
//			{
//				leftchild = false;
//				return;
//			}
//			if (c >= 'A' && c <= 'z')
//			{
//				vector1.push_back(n);
//				queue1.push(n);
//			}
//			else
//				queue1.push(n);
//		}
//	}
//}

////////////////////////////biuld_2///////////////////////////////

//void tree::biuld2(char x, string s)
//{
//	node* p;
//	node* q;
//	node* n;
//	if (s == "")
//	{
//		n = new node(NULL, x, NULL);
//		root = n;
//	}
//	else
//	{
//
//		p = root;
//		int counter = 0;
//		while (counter != s.length())
//		{
//			if (s[counter] == 'r' || s[counter] == 'R')
//			{
//				if (p != NULL && counter != s.length())
//				{
//					q = p;
//					p = p->get_rChild();
//					counter++;
//					if (p == NULL && counter == s.length())
//					{
//						n = new node(NULL, x, NULL);
//						q->set_rChild(n);
//						cout << "accepted" << endl;
//					}
//				}
//				else
//				{
//					if (counter == s.length())
//						counter++;
//					break;
//				}
//			}
//			else if (s[counter] == 'l' || s[counter] == 'L')
//			{
//				if (p != NULL && counter != s.length())
//				{
//					q = p;
//					p = p->get_lChild();
//					counter++;
//					if (p == NULL && counter == s.length())
//					{
//						n = new node(NULL, x, NULL);
//						q->set_lChild(n);
//						cout << "accepted" << endl;
//					}
//				}
//				else
//				{
//					if (counter == s.length())
//						counter++;
//					break;
//				}
//			}
//		}
//		if (counter != s.length() || p != NULL)
//			cout << "wrong node" << endl;
//	}
//}

/////////////////////////////////////////////////////////////////

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

void tree::permutation(int n,string ss)
{
	int l = (int)pow(2, (double)n);
	//char**s = new char*[l];
	char* prevperm = new char[n];
	char* currentperm = new char[n];
	//for (int i = 0; i < l; i++)
	//{
	//	  s[i] = new char[n];
	//}
	//for (int i = 0; i < l; i++)
	//{
	for (int j = 0; j < n; j++)
	{
		currentperm[j] = '0';
		prevperm[j] = '0';
		//s[i][j] = '0';
	}
	//}
	char c = FT(ss, prevperm);
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
				//s[i][j] = '1';
				for (int k = 0; k < j; k++)
				{
					currentperm[k] = prevperm[k];
					//s[i][k] = s[i - 1][k];
				}
				break;
			}
			else
			{
				//s[i][j] = '0';
				currentperm[j] = '0';
				x = 0;
			}
		}
		/*for (int w = 0; w < n; w++)
		{
			cout << currentperm[w];
		}*/
		//cout << endl;
		char c = FT(ss, currentperm);
		if (c == 'T')
			_counter++;
		for (int r = 0; r < n; r++)
		{
			prevperm[r] = currentperm[r];
			currentperm[r] = '0';
		}
	}
}

string* tree::permutation2(int n, string sss)
{
	int tedad = (int)pow(2.0, n);
	string* ss = new string[tedad];
	int k = 0;
	//int g = 0;
	int jadidt = tedad / 2;
	int counter = 0;
	while (k < n)
	{
		int b = 0;
		while (b < tedad)
		{
			for (int i = 0; i < jadidt; i++)
			{
				ss[counter] += "T";
				counter++;
				b++;
			}
			for (int j = jadidt; j < jadidt * 2; j++)
			{
				ss[counter] += "F";
				counter++;
				b++;
			}
		}
		counter = 0;
		k++;
		jadidt = jadidt / 2;
	}
	return ss;
}

///////////////////////////////////////////////////////////

string tree::postorder()
{
	string ans = "";
	stack<node*> s2;
	node* currentnode = array[1];
	while (true)
	{
		while (currentnode != NULL)
		{
			ans += currentnode->get_value();
			s2.push(currentnode);
			currentnode = currentnode->get_rChild();
		}
		if (!s2.empty())
		{
			currentnode = s2.top();
			s2.pop();
			currentnode = currentnode->get_lChild();
		}
		else
			break;
	}
	string ans_r = "";
	for (int i = ans.length() - 1; i >= 0; i--)
	{
		ans_r += ans[i];
	}
	ans="";
	return ans_r;
}

///////////////////////////////////////////////////////////

char tree::FT(string s, char* ss)
{
	//stack<node*> qq;
	vector<node*> aa;
	
	int counter = 0;

	for (size_t i = 0; i < vector1.size(); i++)
	{
		if (ss[i] == '0')
		//if (ss[i] == 'T')
			vector1[i]->set_TF('T');
		else
			vector1[i]->set_TF('F');
	}

	while (counter != s.length())
	{
		if (s[counter] == '&' || s[counter] == '|' || s[counter] == '!')
		{
			if (s[counter] == '&')
			{
				counter++;
				node* p = aa.back();
				aa.pop_back();
				node* k = aa.back();
				aa.pop_back();
				/*node* p = qq.top();
				qq.pop();
				node* k = qq.top();
				qq.pop();*/
				bool flag1 = false;
				bool flag2 = false;
				for (size_t i = 0; i < vector1.size(); i++)
				{
					if (p->get_TF() == '\0' && p->get_value() == vector1[i]->get_value())
					{
						p->set_TF(vector1[i]->get_TF());
						flag1 = true;
					}
					if (k->get_TF() == '\0' && k->get_value() == vector1[i]->get_value())
					{
						k->set_TF(vector1[i]->get_TF());
						flag2 = true;
					}
					if (flag1 == true && flag2 == true)
						break;
				}
				node* t = new node();
				if (p->get_TF() == 'T' && k->get_TF() == 'T')
				{
					t->set_TF('T');
					t->set_value('T');
				}
				else
				{
					t->set_TF('F');
					t->set_value('F');
				}
				aa.push_back(t);
				
				//qq.push(t);
			}
			else if (s[counter] == '|')
			{
				counter++;
				node* p = aa.back();
				aa.pop_back();
				node* k = aa.back();
				aa.pop_back();
				/*node* p = qq.top();
				qq.pop();
				node* k = qq.top();
				qq.pop();*/
				bool flag1 = false;
				bool flag2 = false;
				for (size_t i = 0; i < vector1.size(); i++)
				{
					if (p->get_TF() == '\0' && p->get_value() == vector1[i]->get_value())
					{
						p->set_TF(vector1[i]->get_TF());
						flag1 = true;
					}
					if (k->get_TF() == '\0' && k->get_value() == vector1[i]->get_value())
					{
						k->set_TF(vector1[i]->get_TF());
						flag2 = true;
					}
					if (flag1 == true && flag2 == true)
						break;
				}
				node* t = new node();
				if (p->get_TF() == 'F' && k->get_TF() == 'F')
				{
					t->set_TF('F');
					t->set_value('F');
				}
				else
				{
					t->set_TF('T');
					t->set_value('T');
				}
				aa.push_back(t);
				
				//qq.push(t);
			}
			else if (s[counter] == '!')
			{
				counter++;
				node* k = aa.back();
				aa.pop_back();
				/*node* k = qq.top();
				qq.pop();*/
				for (size_t i = 0; i < vector1.size(); i++)
				{
					if (k->get_TF() == '\0' && k->get_value() == vector1[i]->get_value())
					{
						k->set_TF(vector1[i]->get_TF());
						break;
					}
				}
				if (k->get_TF() == 'T')
				{
					k->set_TF('F');
					k->set_value('F');
				}
				else
				{
					k->set_TF('T');
					k->set_value('T');
				}
				aa.push_back(k);
				
				//qq.push(k);
			}
		}
		else
		{
			node* r;
			if (s[counter] == 'T' || s[counter] == 'F')
				r = new node(s[counter], s[counter], NULL);
			else
				r = new node(s[counter], NULL, NULL);
			aa.push_back(r);
			//qq.push(r);
			counter++;
		}
	}
	//return qq.top()->get_TF();
	return aa.back()->get_TF();
}

///////////////////////////////////////////////////////////



///////////////////////////////////////////////////////////

void tree::print(node* parent)
{
	node* p = parent;
	if (p->get_value() != NULL)
		cout << p->get_Index() << " -> " << p->get_value() << endl;
	else
		cout << p->get_Index() << " -> " << p->get_TF() << endl;
	if (p->get_lChild() != NULL)
		print(p->get_lChild());
	if (p->get_rChild() != NULL)
		print(p->get_rChild());
	return;
}

///////////////////////////////////////////////////////////


int main()
{
	tree* a = new tree();
	//a->permutation(14);
	int n, m;
	cin >> n >> m;
	a->set_Array_Length(n);
	char c;
	for (int i = 1; i <= n; i++)
	{
		cin >> c;
		if (c >= 'A' && c <= 'z' && c != 'T' && c != 'F')
		{
			size_t i = 0;
			for (i = 0; i < a->vector1.size(); i++)
				if (a->vector1[i]->get_value() == c)
					break;
			if (i == a->vector1.size())
			{
				node* p = new node();
				p->set_value(c);
				a->vector1.push_back(p);
				//delete p;
			}
		}
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
	int counter = 0;
	//a->print(a->array[1]);
	//string* b = a->permutation2(a->vector1.size());
	if (n > 1)
	{
		string ss = a->postorder();
		a->permutation(a->vector1.size(), ss);
		/*for (int i = 0; i < pow(2, (double)a->vector1.size()); i++)
		{
			char c = a->FT(ss, b[i]);
			if (c == 'T')
				counter++;
		}*/
		//ss.clear();
		//delete[] b;
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
	//char** b=a->permutation(3);
	//a->biuld('+');
	//a->biuld('*');
	//a->biuld('c');
	//a->biuld('a');
	//a->biuld('!');
	//a->biuld('0');
	//a->biuld('0');
	//a->biuld('0');
	//a->biuld('0');
	//a->biuld('0');
	//a->biuld('b');
	//stack<node*> ss;
	//ss=a->postorder();
	//for (size_t i = 0; i < pow(2,3); i++)
	//{
	//	for (size_t j = 0; j < 3; j++)
	//	{
	//		if (b[i][j] == '0')
	//			cout << "T" << " ";
	//		else
	//			cout << "F" << " ";
	//	}
	//	cout << endl;
	//}
	//for (size_t i = 0; i < pow(2, 3); i++)
	//{
	//	cout << a->FT(ss, b[i]) << endl;
	//}
	//a->biuld2('1', "");
	//a->biuld2('2', "rr");
	//a->biuld2('3', "r");
	//a->biuld2('4', "l");
	//a->biuld2('5', "ll");
	//a->biuld2('6', "lll");
	//a->biuld2('7', "rrr");
	//a->biuld2('8', "r");
	//a->biuld2('9', "l");
	//a->biuld2('10', "llll");
	//cout << infix2postfix("!(!(!(!a+!b))*!((!c/!d)/!(!e-!f)))");
	_getch();
	return 0;
}
