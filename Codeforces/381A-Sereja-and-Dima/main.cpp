#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    int s=0 , d=0, a=2, j=0, k=n-1;
    while (j <= k)
    {
        if(a%2==0) {
            if(v[j] > v[k])
            {
                s += v[j];
                j++;
            }
            else
            {
                s += v[k];
                k--;
            }
            a++;
        }
        else {
            if(v[j] > v[k])
            {
                d += v[j];
                j++;
            }
            else
            {
                d += v[k];
                k--;
            }
            a++;
        }
    }
    cout << s << " " << d;
    return 0;
}
