#include <bits/stdc++.h>
using namespace std;


int main()
{
    int y;cin >> y;
    int x;
    map<int, int> m;
    while(true){
        y++;
        x=y;
        for (int var = 0; var < 4; ++var) {
            m[x%10]++;
            x/=10;
        }
        if(m.size() == 4){
            cout << y;
            return 0;`
        }
        else{
            m.clear();
        }
    }
    return 0;
}
