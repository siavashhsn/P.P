#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v.push_back(a);
    }
    int i=0, j=n-1, counti=0, countj=0;
    while(i < j)
    {
        if(i + 1 == j)
        {
            counti++;
            countj++;
            break;
        }
        if(v[i] > v[j])
        {
            v[i] -= v[j];
            countj++;
            j--;
        }
        else if(v[i] < v[j])
        {
            v[j] -= v[i];
            counti++;
            i++;
        }
        else if(v[i] == v[j])
        {
            counti++;
            countj++;
            i++;
            j--;
            if(i == j)
            {
                counti++;
                break;
            }
        }
    }
    if(n==1)
        cout << 1 << " " << 0;
    else
        cout << counti << " " << countj;
    return 0;
}
