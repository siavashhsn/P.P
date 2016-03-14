#include <iostream>
#include <string>
using namespace std;

int main()
{
    string si, so;
    cin >> si;
    for (size_t i = 1; i < si.length(); ++i) {
        if(si[i] >= 'a') {
            cout << si;
            return 0;
        }
    }

    for (size_t i = 0; i < si.length(); ++i) {
        if (si[i] >= 'a')
            si[i] -= 32;
        else if (si[i] < 'a')
            si[i] += 32;
    }
    cout << si;
    return 0;
}
