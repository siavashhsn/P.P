#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int ans=0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if(s[0] == '+' || s[0] == '-') {
            if(s[0] == '+')
                ans++;
            else ans--;
        }
        else {
            if(s[2] == '+')
                ans++;
            else ans--;
        }
    }
    cout << ans;
    return 0;
}
