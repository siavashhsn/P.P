#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, a, c=0;
	cin >> n >> m;
	vector<int> v;
	int mm[11];
	for(int i=0; i<11; i++){
		mm[i]=0;
	}
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
		mm[a]++;
	}

	for(int i=n-1; i>=0; i--){
		c+=i-mm[v[i]]+1;
		mm[v[i]]--;
	}

	cout << c;
return 0;
}
