#include <iostream>
using namespace std;

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    if(n >= 2)
    {
        count += m;
        n -= 2;
        while(n >= 2)
        {
            count += m;
            n -= 2;
        }
        if(n == 1 && m >= 2)
        {
            int i = m/2;
            count += i;
        }
        cout << count;
        return 0;
    }
    else
    {
        if(m >= 2)
        {
            count+= m/2;
        }
        cout << count;
        return 0;
    }
    return 0;
}
