#include "stdafx.h"
#include <stack>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class pre;
class post;
pre* post2pre(post const *p);
////////////////////////////////////////////////////

//////////////////////get_token/////////////////////
char get_token(char a)
{
	switch (a)
	{
	case '-': return '-';
	case '+': return '+';
	case '*': return '*';
	case '/': return '/';
	default:  return 'o';
	}
}
///////////////////////postfix//////////////////////
class post
{
	friend class pre;
public:
	string s;
	char postexp[100];
	post(char n[100])
	{
		for (size_t i = 0; i < 100; i++)
		{
			postexp[i] = n[i];
		}
	}
	post(string s)
	{
		this->s = s;
	}
	post(){}
	post* pre2post(pre const *p);
	double evalpost(post const p[]);
};
////////////////////////refix///////////////////////
class pre
{
	friend class post;
public:
	char preexp[100];
	string s;
	pre(char preexp[100])
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->preexp[i] = preexp[i];
		}
	}
	pre(string s)
	{
		this->s = s;
	}
	pre(){}
	pre* post2pre(post const *p);
	double evalpre(pre const p[]);
};
///////////////////prefix2postfix///////////////////
post* post::pre2post(pre const *p)
{
	stack<string> poststack;
	string temp = "";
	string temp1 = "";
	string temp2 = "";
	string result;
	size_t n = 0;
	for (size_t i = 0; p->preexp[i] != '\0'; i++) n++;
	n--;

	auto token = get_token(p->preexp[n]);
	while (true)
	{
		temp = p->preexp[n];
		if (token == 'o')
			poststack.push(temp);
		else
		{
			result += poststack.top();
			poststack.pop();
			result += poststack.top();
			poststack.pop();
			result += token;
			poststack.push(result);
		}
		result;
		result = "";
		if (n > 0)
			n--;
		else
			break;
		token = get_token(p->preexp[n]);
	}
	return new post(poststack.top());
}
/////////////////postfix2prefix/////////////////
pre* pre::post2pre(post const *p)
{
	stack<string> prestack;
	string temp = "";
	string s;
	string temp1 = "";
	string temp2 = "";
	size_t n = 0;
	auto token = get_token(p->postexp[n]);
	while (p->postexp[n] != '\0')
	{
		temp = p->postexp[n];
		if (token == 'o')
			prestack.push(string(temp));
		else
		{
			s += token;
			temp2 = prestack.top();
			prestack.pop();
			temp1 = prestack.top();
			prestack.pop();
			s += temp1 + temp2;
			prestack.push(s);
		}
		s;
		s = "";
		n++;
		token = get_token(p->postexp[n]);
	}
	return new pre(prestack.top());
}
////////////////////////////////////////////////////
int main()
{
	char expArray[100] = { 'a', 'b', '+', 'c', '*', 'd', '-', 'e', 'f', '/', 'g', 'h', '+', '/', '+' };
	char expArray1[100] = { '+', '-', '*', '+', 'a', 'b', 'c', 'd', '/', '/', 'e', 'f', '+', 'g', 'h'};
	string s;
	string output[1000];
	char exp[1000];
	size_t n;
	cin >> n;
	post* p;
	pre* pp;
	for (size_t i = 0; i < n; i++)
	{

		cin >> s >> exp;
		if (s == "post2pre")
		{
			p = new post(exp);
			output[i] = pp->post2pre(p)->s;
		}
		else
		{
			pp = new pre(exp);
			output[i] = p->pre2post(pp)->s;
		}
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << output[i] << endl;
	}
	return 0;
}
////////////////////////////////////////////////////