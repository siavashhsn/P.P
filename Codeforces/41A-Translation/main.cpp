#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, ss, sss;
    cin >> s >> ss;
    for(int i=ss.length()-1; i>=0; i--)
    {
        sss+=ss[i];
    }

    if(sss == s)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
