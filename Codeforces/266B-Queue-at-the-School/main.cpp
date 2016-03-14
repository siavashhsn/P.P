#include <bits/stdc++.h>
using namespace std;

int main()
{
    size_t n, m; cin >> n >> m;
    string s; cin >> s;
    for (size_t var = 0; var < m; ++var) {
        for (size_t v = 0; v < s.length();) {
            if(s[v] == 'B') {
                if(v+1 < s.length() && s[v+1] == 'G') {
                    s[v] = 'G';
                    s[v+1] = 'B';
                    v+=2;
                }
                else v++;
            }
            else v++;
        }
    }
    cout << s;
    return 0;
}
