#include "stdafx.h"
#include <stack>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class edge;
class node;
class NFA;



int p_in_s(char c)
{
	switch (c)
	{
	case '+': return 1;
	case '-': return 1;
	case '.': return 2;
	case '/': return 2;
	case '*': return 0;
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
	case '.': return 2;
	case '/': return 2;
	case '*': return 3;
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
		else if (s[i] == '*'/* && s[i + 1] >= 'A' && s[i + 1] <= 'z'*/)
		{
			//postfix += s[i + 1];
			postfix += s[i];
			//i++;
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
						if (!stack.empty() && stack.top() == '*')
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

////////////////////////////////////////////////////////////////

class edge
{
public:
	char value;
	node* home;
	node* end;
	char visited;
	edge(char value, node* home, node* end)
	{
		this->value = value;
		this->home = home;
		this->end = end;
		visited = 'F';
	}
};

class node
{
public:
	int value;
	vector<edge*> v;
	node(int value){ this->value = value; }
};

class collection
{
public:
	node* start;
	node* finish;
};

class NFA
{
	
public:
	vector<edge*> alledge;
	stack<collection*> s;
	int namecount = 0;
	string postexp;
	NFA(string postexp)
	{
		this->postexp = infix2postfix(postexp);
	}
	NFA(){}
	void biuldNFA();
};

void NFA::biuldNFA()
{
	int i = 0;
	while (i!=postexp.length())
	{
		if (postexp[i] >= 'A' && postexp[i] <= 'z')
		{
			node* p = new node(namecount);
			namecount++;
			node* q = new node(namecount);
			namecount++;
			edge* r = new edge(postexp[i], p, q);
			this->alledge.push_back(r);
			p->v.push_back(r);
			q->v.push_back(r);
			collection* c = new collection();
			c->start = p;
			c->finish = q;
			s.push(c);
			i++;
		}
		else
		{
			if (postexp[i] == '*')
			{
				node* p = new node(namecount);
				namecount++;
				node* q = new node(namecount);
				namecount++;
				collection* c = s.top();
				s.pop();
				edge* a = new edge((char)229, p, c->start);
				this->alledge.push_back(a);
				p->v.push_back(a);
				edge* b = new edge((char)229, c->finish, q);
				this->alledge.push_back(b);
				c->finish->v.push_back(b);
				edge* d = new edge((char)229, p, q);
				this->alledge.push_back(d);
				p->v.push_back(d);
				edge* e = new edge((char)229, q, p);
				this->alledge.push_back(e);
				q->v.push_back(e);
				collection* f = new collection();
				f->start = p;
				f->finish = q;
				s.push(f);
				i++;
			}
			else if (postexp[i] == '.')
			{
				collection* c = new collection();
				collection* a = s.top();
				s.pop();
				collection* b = s.top();
				s.pop();
				edge* r = new edge((char)229, b->finish, a->start);
				this->alledge.push_back(r);
				b->finish->v.push_back(r);
				c->start = b->start;
				c->finish = a->finish;
				s.push(c);
				i++;
			}
			else if (postexp[i] == '+')
			{
				node* p = new node(namecount);
				namecount++;
				node* q = new node(namecount);
				namecount++;
				collection* a = s.top();
				s.pop();
				collection* b = s.top();
				s.pop();
				edge* r = new edge((char)229, p, a->start);
				this->alledge.push_back(r);
				p->v.push_back(r);
				edge* l = new edge((char)229, p, b->start);
				this->alledge.push_back(l);
				p->v.push_back(l);
				edge* m = new edge((char)229, a->finish, q);
				this->alledge.push_back(m);
				a->finish->v.push_back(m);
				edge* n = new edge((char)229, b->finish, q);
				this->alledge.push_back(n);
				b->finish->v.push_back(n);
				collection* c = new collection();
				c->start = p;
				c->finish = q;
				s.push(c);
				i++;
			}
		}
	}
}

vector<pair<char,pair<node*, node*>>> output;
stack<node*> sout;
void print(node* start)
{
	node* p = start;
	while (true)
	{
		for (size_t i = 0; i < p->v.size(); i++)
		{
			if (p->v[i]->visited == 'F')
			{
				pair<node*, node*> pp;
				pp.first = p->v[i]->home;
				pp.second = p->v[i]->end;
				pair<char, pair<node*, node*>> qq;
				qq.first = p->v[i]->value;
				qq.second = pp;
				output.push_back(qq);
				p->v[i]->visited = 'T';
				sout.push(p->v[i]->end);
			}
		}
		if (sout.empty())
			break;
		p = sout.top();
		sout.pop();
	}
	cout << output.size() << endl;
	for (size_t i = 0; i < output.size(); i++)
		cout 
		<< output[i].first << " : (" 
		<< output[i].second.first->value << "," 
		<< output[i].second.second->value << ")" 
		<< endl;
}


int main()
{
	NFA* a = new NFA("(a+a.b)*");
	a->biuldNFA();
	stack<edge> s;
	print(a->s.top()->start);
	cout << "**************************" << endl;
	cout << a->postexp << endl << a->alledge.size() << endl;
	for (size_t i = 0; i < a->alledge.size(); i++)
	{
		cout << a->alledge[i]->value << " : (" << a->alledge[i]->home->value << "," << a->alledge[i]->end->value << ")" << endl;
	}
	return 0;
}