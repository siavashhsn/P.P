#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, m, p;
    cin >> n >> m;
    vector<ll> v;

    v.push_back(-1);
    for(ll i=1; i<=n; i++){
        cin >> p;
        v.push_back(p);
    }

    ll l, r, x;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r >> x;



//        int q=-1;
//        for (int j = l; j <= r; ++j) {
//            if(v[j]!=x) {
//                q=j;
//                break;
//            }
//        }
//        cout << q << endl;
    }

    return 0;
}
