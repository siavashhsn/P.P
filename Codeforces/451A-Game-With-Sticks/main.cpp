#include <iostream>
#include <string>
using namespace std;

int main()
{
    while (true)
    {
        int n, m;
        cin >> n >> m;
        int var1 = n;
        int var2 = m;
        char c = 'M';
        while(var1 > 0 && var2 > 0) {
            if(c=='A')
                c = 'M';
            else
                c = 'A';
            var1--;
            var2--;
        }
        if(c == 'A')
            cout << "Akshat";
        else
            cout << "Malvika";
    }
    return 0;
}
