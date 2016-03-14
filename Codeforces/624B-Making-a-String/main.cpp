//#include <stdlib.h>
#include <bits/stdc++.h>
#define FOR(i,k,m) for(int i = k; i < m; i++)
#define LL long long
using namespace std;


int main()
{
    LL n,a[26];
    cin >> n;

    FOR(i,0,n) { cin >> a[i]; }

    LL b[26],l=0;
    sort(a, a + n);
    b[0] = a[0];
    int i=1;
    LL x;
    FOR(aa, 1, n) {
        x=a[aa];
        FOR(bb, 0, i) {
            if(x == b[bb]) {
                x--;
            }
        }
        b[i] = x;
        i++;
        sort(b, b + i,greater<LL>());
    }

    FOR(i,0,n) {
        if(b[i] > 0) l+=b[i];
    }
    cout << l;
    return 0;
}
