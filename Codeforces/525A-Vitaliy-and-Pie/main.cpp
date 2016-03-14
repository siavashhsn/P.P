#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    size_t i=0, count=0;
    int array[32];
    for (int var = 0; var < 32; ++var) {
        array[var] = 0;
    }
    while (i < s.length())
    {
        if(s[i] != s[i + 1] + 32)
        {
           array[s[i] - 97]++;
           if(array[s[i + 1] - 65] != 0)
               array[s[i + 1] - 65]--;
           else
               count++;
        }
        i += 2;
    }
    cout << count;
    return 0;
}
