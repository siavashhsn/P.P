#include <iostream>
#include <map>
using namespace std;

#define for(i, n) for((i)=0; (i)<(n); (i)++)
typedef multimap<int, int> M;

int main()
{
	int n; 
	cin >> n;
	int i, a, b;
	M m, mm;
	for(i, n) {
		cin >> a >> b;
		m.insert(make_pair(a, b));
	}
	mm=m;
	for(auto& i:mm) {
		
	}
	return 0;
}