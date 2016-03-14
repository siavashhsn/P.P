#include <iostream>
using namespace std;

int main()
{
    int n, m, h[100]={};cin >> n;
    for(int i=1; i<=n; i++){
        cin >> m;
        h[m]=i;
    }
    for(int i=1; i<=n; i++){
        cout << h[i] << " ";
    }
    return 0;
}
