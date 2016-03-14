#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, c=0;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        if(i%m == 0)
            n++;
        c++;
    }
    cout << c;
    return 0;
}
