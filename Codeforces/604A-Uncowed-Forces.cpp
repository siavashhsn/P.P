#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int m[5];
	int w[5];
	int h[2];
	int sum=0;
	cin >> m[0] >> m[1] >> m[2] >> m[3] >> m[4];
	cin >> w[0] >> w[1] >> w[2] >> w[3] >> w[4];
	cin >> h[0] >> h[1];
	int x[5]={500, 1000, 1500, 2000, 2500};
	for(int i=0; i<5; i++){
		sum += max(3*x[i]/10, x[i]-((x[i]*m[i])/250)-(w[i]*50));
	}
	sum += 100*h[0];
	sum -= 50*h[1];
	cout << sum;
	return 0;
}
