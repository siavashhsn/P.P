#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m=0;
    cin >> n;
    for(int i=0; ;i++)
    {
        m+=i;
        if(n<=m)
        {
            m-=i;
            cout << n-m;
            return 0;
        }
    }
    return 0;
}
