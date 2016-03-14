#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    vector<pair<int ,int> > v;
    cin >> n;
    for (int var = 0; var < n; ++var) {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    int m=0,k=0;
    for (int i = 0; i < n -1; ++i) {
        for (int j = 0; j <= i; ++j) {
            int l = v[j].second;
            int h = v[j].first;
            m += l;
            m -= h;
        }
        if(m > k)
            k=m;
        m=0;
    }
    cout << k;
    return 0;
}
