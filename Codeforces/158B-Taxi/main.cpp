#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int var = 0; var < n; ++var) {
        int m;
        cin >> m;
        v.push_back(m);
    }
    bool flag = false;
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = v.size()-1; j > i; --j) {
            if(v[i] + v[j] <= 4)
            {
                flag = true;
                v[j] += v[i];
                v[i] = 0;
                break;
            }
            else flag=false;
        }
        if (flag == false)
            break;
    }
    int count = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        if(v[i] != 0)
            count++;
    }
    cout << count;
    return 0;
}
