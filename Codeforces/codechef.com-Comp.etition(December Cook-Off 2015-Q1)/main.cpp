#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;cin >> m;
    int a[55];
    int n;
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> n;
        for(int j=0; j < n; j++)
        {
            cin >> a[j];
            int s=0;
            int p=1;
            for(int k=j; k >= 0; k--)
            {
                s+=a[k];
                p*=a[k];
                if(s==p) ans++;
            }
        }
        cout << ans << endl;
        ans=0;
    }
    return 0;
}
