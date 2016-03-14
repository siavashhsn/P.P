#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    for(int i=0; ;i++){
        if(i%2==0){
            int x = __gcd(a,c);
            if(x>c){cout << 1; return 0;}
            else c -= x;
        }
        else{
            int x = __gcd(b,c);
            if(x>c){cout << 0; return 0;}
            else c -= x;
        }
    }
    return 0;
}
