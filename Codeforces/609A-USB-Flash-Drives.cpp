#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, a;
	cin >> n >> m;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i=0; i<n; i++){
		m-=v[i];
		if(m<=0){
			cout << i+1;
			return 0;
		}
	}

return 0;
}
