#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define f(i, k, n, c) 	for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)	for(decltype(k+n) i=k; i>n; i c)
#define ff(i, n)      	for(decltype(n)   i=0; i<n; i++)
typedef long long ll;

bool gam(int a,int b,int c)
{
    if((a*a==b*b + c*c) || (b*b == a*a + c*c) || (c*c==a*a+b*b))
        return true;
    return false;
}


int main()
{
    int a1, a2, a3, b1, b2, b3;
    cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;

    if(!gam(a1,a2,a3))
    {
        cout<<"NO";
        return 0;
    }
    if(!gam(b1,b2,b3))
    {
        cout<<"NO";
        return 0;
    }
    int a[3],b[3];
    a[0]=a1,a[1]=a2,a[2]=a3;
    b[0]=b1,b[1]=b2,b[2]=b3;
    sort(a,a+3);
    sort(b,b+3);
    if(a[0]==b[0] && a[1]==b[1])
        cout<<"YES";
    else
        cout<<"NO";



    return 0;
}
