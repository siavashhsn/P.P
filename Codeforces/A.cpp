#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
#define f(i, k, n, c) 	for(decltype(k+n) i=k; i<n; i c)
#define fr(i, k, n, c)	for(decltype(k+n) i=k; i>n; i c)
#define ff(i, n)      	for(decltype(n)   i=0; i<n; i++)
typedef long long ll;


int main()
{
    vector<pair<int, char>> v;
    string s;
    cin >> s;
    f(i, 0, s.length(), ++) {
        bool flag = false;
        f(j, 0, v.size(), ++) {
            if(v[j].second == s[i]) {
                v[j].first++;
                flag = true;
                break;
            }
        }
        if(flag == false){
            v.push_back({1,s[i]});
        }
        flag = false;
    }

    sort(v.begin(), v.end());
    // f(i, 0, v.size(), ++)
    //     cout<< v[i].second << " " << v[i].first << endl;
    int com=v.size(), c=0;
    if(com <= 2) {cout << 0; return 0;}
    f(i, 0, v.size(), ++)
    {
        c+=v[i].first;
        com--;
        if(com==2)
        {
            cout << c;
            return 0;
        }
    }

    return 0;
}
