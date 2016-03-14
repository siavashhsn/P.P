#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, p;
    cin >> n >> m;
    vector<int> v;
    for(int i=0; i < m; i++){
        cin >> p;
        v.push_back(p);
    }

    sort(v.begin(), v.end());
    int min = v[n-1]-v[0];
    for (int var = 1; (n -1) + var < m; ++var) {
        if(v[(n-1)+var] - v[var] < min)
            min = v[(n-1)+var] - v[var];
    }

    cout <<  min;
    return 0;
}
