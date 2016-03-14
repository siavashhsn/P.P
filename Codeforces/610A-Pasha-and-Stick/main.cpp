#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int x;
    cin >> x;

    if(x%2 != 0)
        cout << 0;
    else if(x <= 4)
        cout << 0;
    else if(x%4==0)
        cout << x/4-1;
    else cout  << x/4;


    return 0;
}
