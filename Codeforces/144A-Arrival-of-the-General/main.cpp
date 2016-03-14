#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,min=101,p=0,max=0,q=0;
    cin >> n;
    vector<int> v;
    for(int i=0; i<n; i++)
    {
        cin >> m;
        v.push_back(m);
        if(m<=min)
        {
            min=m;
            p=i;
        }
        else if(m>max)
        {
            max=m;
            q=i;
        }
    }

    if(p<q)
        cout << n-1-p+q-1;
    else
        cout << n-1-p+q;

    return 0;
}
