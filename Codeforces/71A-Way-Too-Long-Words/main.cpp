#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    size_t n;
    cin >> n;
    vector<pair<string , pair<int , char> > > v;
    for (size_t var = 0; var < n; ++var) {
        string s;
        cin >> s;
        if(s.length()>10)
        {
            cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
        }
        else
            cout << s << endl;
    }
    return 0;
}
