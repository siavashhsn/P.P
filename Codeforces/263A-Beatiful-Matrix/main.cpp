#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[5][5];
    int ii, jj;
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin >> a[i][j];
            if(a[i][j] == 1){
                ii=i;
                jj=j;
            }
        }
    }

    cout << abs(2-ii)+abs(2-jj);

    return 0;
}
