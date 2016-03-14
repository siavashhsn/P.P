#include <bits/stdc++.h>
using namespace std;


vector<char> add(char c1[100000], int c1size, char c2[100000], int c2size)
{
    int carry = 0;
    vector<char> sum;
    vector<char>::iterator first;
    int i=c1size-1, j=c2size-1;
    for(; i>=0 && j>=0; i--, j--)
    {
        int a = carry + ((c1[i] + c2[j]) - 96);
        first = sum.begin();
        if(a>=9)
        {
            carry = a/10;
            a = a%10;
            sum.insert(first, a+48);
        }
        else
        {
            sum.insert(first, a+48);
            carry = 0;
        }
    }

    if(i>=0)
    {
        while(i>=0)
        {
            int a = carry + (c1[i] - 48);
            first = sum.begin();
            if(a>=9)
            {
                carry = a/10;
                a = a%10;
                sum.insert(first, a+48);
            }
            else
            {
                sum.insert(first, a+48);
                carry = 0;
            }
            i--;
        }
    }
    else if(j>=0)
    {
        while(j>=0)
        {
            int a = carry + (c2[j] - 48);
            first = sum.begin();
            if(a>=9)
            {
                carry = a/10;
                a = a%10;
                sum.insert(first, a+48);
            }
            else
            {
                sum.insert(first, a+48);
                carry = 0;
            }
            j--;
        }
    }
    if(carry != 0)
    {
        first = sum.begin();
        sum.insert(first, carry+48);
    }

    return sum;
}

int main()
{
    char c1[100000];

    char c2[100000];

    cin >> c1 >> c2;
    int c1size = 0;
    int c2size = 0;

    while(c1[c1size] != '\0')
        c1size++;
    while(c2[c2size] != '\0')
        c2size++;
    vector<char> v=add(c1, c1size, c2, c2size);

    for(int i=0; i<v.size(); i++) cout << v[i];

    return 0;
}
