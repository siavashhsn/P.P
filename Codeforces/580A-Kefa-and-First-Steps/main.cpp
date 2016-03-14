#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

int main()
{
    LL n, m, min=0, count=0;
    vector<LL> v;
    cin >> n;

    for(LL i=0; i<n; i++){
        cin >> m;
        if(m>=min){
            count++;
            min = m;
        }
        else {
            v.push_back(count);
            count=1;
            min = m;
        }
    }
    v.push_back(count);
    sort(v.begin(), v.end(),greater<LL>());
    cout << v[0];
    return 0;
}
