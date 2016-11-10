#include <iostream>
using namespace std;

int main()
{
	long long n, m, min=0, max=0; cin >> n;
	m=n;
	int j=1, k=1;
	for(long long i=1; i<=n; i++) {
		if(j<=2) {
			j++;
			max++;
		}
		else {
			k++;
			if(k>5) {
				k=1;
				j=1;
			}
		}
	}
	k=1;j=1;
	for(long long i=1; i<=n; i++) {
		if(k<=5) {
			k++;
		}
		else {
			j++;
			min++;
			if(j>2) {
				k=1;
				j=1;
			}
		}
	}
	cout << min << " " << max;
	return 0;
}