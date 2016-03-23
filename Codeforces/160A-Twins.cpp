#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;cin >> n;
	int m;
	int sum=0, summ=0, count=0;
	vector<int> v;
	for(int i=0; i<n; i++){
		cin >> m;
		v.push_back(m);
		sum+=m;
	}
	sort(v.begin(), v.end(), greater<int>());
	for(int i=0; i<n; i++){
		summ+=v[i];
		sum-=v[i];
		count++;
		if(summ>sum)break;
	}
	cout << count;
return 0;
}
