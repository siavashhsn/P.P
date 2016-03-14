#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s, ss;
    cin >> s;
    vector<char> v;
    for (size_t i = 0; i < s.length(); i+=2) {
            v.push_back(s[i]);
    }
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); ++i) {
        if(i != v.size()-1)
        {
            ss += v[i];
            ss += '+';
        }
        else
            ss += v[i];
    }
    cout << ss;
    return 0;
}
