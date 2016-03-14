#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans;
    for (size_t var = 0; var < s.length(); ++var) {
        if(s[var] >='A' && s[var] <= 'Z')
            s[var] += 32;

        if(s[var] != 'a' && s[var] != 'e' && s[var] != 'o' && s[var] != 'i' && s[var] != 'u' && s[var] != 'y')
        {
            ans+='.';
            ans+=s[var];
        }
    }
    cout << ans;
    return 0;
}
