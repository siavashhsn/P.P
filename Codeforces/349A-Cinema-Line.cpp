#include <iostream>
using namespace std;

int main()
{
int a;
cin >> a;
int b;
int a25 = 0;
int a50 = 0;
for(int i= 0; i < a; i++)
{
	cin >> b;
	if(b == 25) a25++;
	else if(b == 50){
		a50++;
		if( a25 == 0 )
		{	cout << "NO"; return 0;		}
		else a25--;
	}
	else if(b == 100)
	{
		if(a50 == 0 && a25 < 3)
		{	cout << "NO"; return 0;		} 
		else if(a50 >= 1 && a25 == 0)
		{	cout << "NO"; return 0;		}
		else if(a50 >= 1 && a25 >= 1)
		{	a50--; a25--;	}
		else a25-=3;
	}
}
cout << "YES";
return 0;
}
