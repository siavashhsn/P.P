#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a, b;
    cin >> n;
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v1.push_back(a);
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> b;
        v2.push_back(b);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i=0, j=0, count=0;
    while(i<n || j<m)
    {
        if(v1[i] >= v2[j])
        {
            if(v1[i] - v2[j] == 1 || v1[i] == v2[j])
            {
                i++;
                j++;
                count++;
                if(i>=n || j>=m)
                    break;
            }
            else
            {
                j++;
                if(i>=n || j>=m)
                    break;
            }
        }
        else
        {
            if(v2[j] - v1[i] == 1)
            {
                i++;
                j++;
                count++;
                if(i>=n || j>=m)
                    break;
            }
            else
            {
                i++;
                if(i>=n || j>=m)
                    break;
            }
        }
    }
    cout << count;

    return 0;
}
