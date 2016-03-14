#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;
int n;
int main()
{
    //int n;
    int i=1;
    while(true){
    //cin >> n;
    usleep(5);
    n=i;
    cout << n%15;
    string a[15] = {"Sheldon", "Leonard", "Penny", "Rajesh",
                    "Howard", "Sheldon", "Sheldon", "Leonard",
                    "Leonard", "Penny", "Penny", "Rajesh",
                    "Rajesh", "Howard", "Howard"};
    if(n > 15 && (n-n%15)%2==0) cout << a[n%15];
    else cout << a[(n%15) - 1];
    i++;

    }
    return 0;
}
