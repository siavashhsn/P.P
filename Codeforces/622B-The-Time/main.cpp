#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int h, m;
    char c;
    cin >> h >> c >> m;
    ll a, p, q;
    cin >> a;

    p=a/60;
    if(p>=1)
    {
        if(p>24){
            q=p%24;
            h+=q;
        }
        else
            h+=p;
        if(h>=24)
            h-=24;
    }
    m+=a%60;
    if(m>=60){
        m-=60;
        h+=1;
        if(h>=24)
        {
            h-=24;
        }
    }
    if(h<10)
        cout<< 0 << h << ":";
    else
        cout<< h << ":";
    if(m<10)
        cout << 0 << m;
    else
        cout << m;

    return 0;
}
