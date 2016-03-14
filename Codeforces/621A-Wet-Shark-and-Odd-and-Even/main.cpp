#include <bits/stdc++.h>
using namespace std;

long long a[100002]={};

int main()
{

    int n; cin >> n;
    long long m,sum=0;
    for(int i=0; i<n; i++){
        cin >> m;
        a[i]=m;
        sum+=m;
    }
    if(sum%2 == 0)
        cout << sum;
    else
    {
        sort(a, a+n,greater<long long>());
        for(int i=n-1; i>=0; i--) {
            if(a[i]%2 != 0) {
                sum -= a[i];
                if(sum%2 == 0) {
                    cout << sum;
                    return 0;
                }
            }
        }
    }
    return 0;
}
