#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, q, count=0;
    cin >> n;
    map<int ,int> m;

    for (int var = 0; var < n; ++var) {
        cin >> p >> q;
        if(q-p >= 2)
            count++;
    }
    cout << count;
    return 0;
}
