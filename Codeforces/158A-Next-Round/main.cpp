#include <iostream>
#include <vector>
using namespace std;

int main()
{
    size_t n, k;
    cin >> n >> k;
    vector<size_t> v;
    for (size_t var = 0; var < n; var++) {
        size_t m;
        cin >> m;
        v.push_back(m);
    }
    if(v[0]==0)
    {
        cout << 0;
        return 0;
    }
    int count=0;
    for (size_t var = 0; var < v.size(); ++var) {
        if(v[var] != 0  && var+1 <= k)
        {
            count++;
        }
        else if(v[var] != 0 && var+1 > k && v[var-1]== v[var])
            count++;
        else
            break;
    }
    cout << count;
    return 0;
}
