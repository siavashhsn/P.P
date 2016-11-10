#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define f(i, k, n, c)   for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)  for(decltype(k+n) i=k; i>n; i c)
#define ff(i, n)        for(decltype(n)   i=0; i<n; i++)
typedef long long ll;


int main()
{
    int n, asa;
    cin >> n;
    vector<int> v;
    f(i, 0, n, ++) {
        cin >> asa;
        v.push_back(asa);
    }
    sort(v.begin(), v.end());
    ll aa=1000000000;
    int j=v.size()-1;
    for(int i=0; i<v.size(); i++){
        if(aa > v[i]+v[j]) {
            aa = v[i] + v[j];
        }
        j--;
    }
    cout << aa;

    return 0;
}
