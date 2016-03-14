#include <bits/stdc++.h>
using namespace std;

int b[105]={0};

int main()
{
    int n, m, p, l, q;
    cin >> n >> m;
    q=m;
    for (int var = 0; var < n; ++var) {
        cin >> p;
        for (int v = 0; v < p; ++v) {
            cin >> l;
            if(b[l] == 0){
                b[l]=1;
                q--;
            }
        }
    }

    if(q==0) cout << "YES";
    else cout << "NO";
    return 0;
}
