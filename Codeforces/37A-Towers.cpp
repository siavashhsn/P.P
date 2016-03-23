#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
	vector<int> v;
	set<int> s;
	map<int, int> m, m2;
	int a, b;
	cin >> a;
	//if(a == 382) { cout << 64 << " " << 7; return 0;}
	for(int i = 0; i < a; i++)
	{
		cin >> b;
		m[b]++;
	}
	//for(map<int, int>::iterator i = m.begin(); i != m.end(); i++)
	//	m2[i->second]=i->first;
	//map<int, int>::iterator ii = m2.end();
	//map<int, int>::iterator i = m2.end();
	//cout << i->first << " " << m.size();
	//for(map<int, int>::iterator i = m.begin(); i != m.end(); i++)
        //{	s.insert(i->second); cout << i->second << endl;		}
	//set<int>::iterator j = s.end();
	//cout << endl << "*******   " << *j;
	for(map<int, int>::iterator i = m.begin(); i != m.end(); i++)
		v.push_back(i->second);
	sort(v.begin(), v.end());
	cout << v[v.size()-1] << " " << m.size();

return 0;
}
