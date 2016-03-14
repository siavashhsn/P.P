//#include <iostream>
//#include <vector>
//using namespace std;

//int main()
//{
//    int n;
//    cin >> n;
//    vector<pair<int, char> > v;
//    for (int var = 0; var < n; ++var) {
//        int m;
//        cin >> m;
//        v.push_back(make_pair(m,'F'));
//    }

//    for (int var = 0; var < v.size()-1; ++var) {
//        if(v[i].first == 100)
//        {
//            for (int i = 0; i < var; ++i) {
//                if(v[i].second == 'F')
//            }

//        }
//    }


//    return 0;
//}



/////////////////////////////////////

//#include "stdafx.h"
//#include<iostream>
//#include<conio.h>
//#include<algorithm>
//using namespace std;
//int n; double k;
//int *arrayn = new int[n];
//char binarysearch(double x, int ss, int ee)
//{
//    int j = 0;
//    int start = ss;
//    int end = ee;
//    int s = ee - ss;
//    int w = 0;
//    int mid;
//    while (w <=s )
//    {
//        start = ss;
//        end = ee;
//        bool flag = false;
//        while (flag == false)
//        {
//            mid = (start + end) / 2;
//            if (arrayn[mid] == x)
//            {
//                s--;
//                flag = true;
//                break;
//            }
//            else if (arrayn[mid] < x)
//            {
//                s--;
//                if (mid == end)
//                    return 'f';
//                start = mid + 1;
//            }
//            else if (arrayn[mid] > x)
//            {
//                s--;
//                if (mid == end)
//                    return 'f';
//                end = mid - 1;
//            }
//        }
//        if (arrayn[mid] == x)
//            break;
//        j++;
//    }
//    return 't';
//}
//int main()
//{
//    cin >> n >> k;
//    int counter = n;
//    for (int i = 0; i < n; i++)
//    {
//        cin >> arrayn[i];
//    }
//    sort(&arrayn[0], & arrayn[n - 1]);
//    //cout << arrayn[0] << arrayn[1] << arrayn[2] << arrayn[3] << arrayn[4] << arrayn[5];
//    for (int g = n - 1; g >= 0; g--)
//    {
//        if (arrayn[g] != 1)
//        {
//            double xx = arrayn[g] * k;
//            char javab = binarysearch(xx, g, n - 1);
//            if (javab == 't')
//                counter -= 1;
//        }
//    }
//    if (n == 1 && k == 1 && arrayn[0] == 1)
//        cout << 1;
//    else cout <<counter;
//     //_getch();
//    return 0;
//}



#include<iostream>
#include<algorithm>

char binarysearch(double x, int ss, int ee);

using namespace std;
int n; double k;
int *arrayn = new int[n];
char *tfarray = new char[n];




int main()
{
    cin >> n >> k;
    int nn = n;
    int counter = 0;
    for (int r = 0; r < n; r++)
    {
        tfarray[r] = 'f';
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arrayn[i];
    }

    sort(&arrayn[0], & arrayn[nn - 1]);
    //cout << arrayn[0] << arrayn[1] << arrayn[2] << arrayn[3] << arrayn[4] << arrayn[5];
    for (int g = 0; g < nn; g++)
    {
        if (arrayn[g] != 1)
        {
            if (tfarray[g] == 'f')
            {
                double xx = arrayn[g] * k;
                char javab = binarysearch(xx, g, n - 1);
                if (javab == 't')
                    counter += 1;
            }
            else
                continue;
        }
    }
    if (n == 1 && k == 1 && arrayn[0] == 1)
        cout << 1;
    else cout <<counter;
    return 0;

}


char binarysearch(double x, int ss, int ee)
{
    int j = 0;
    int start = ss;
    int end = ee;
    int s = ee - ss;
    int w = 0;
    int mid;

    while (w <=s )
    {
        start = ss;
        end = ee;
        bool flag = false;
        while (flag == false)
        {
            mid = (start + end) / 2;
            if (arrayn[mid] == x)
            {
                s--;
                flag = true;
                tfarray[mid] = 't';
                break;
            }
            else if (arrayn[mid] < x)
            {
                s--;
                if (mid == end)
                    return 'f';
                    start = mid + 1;
            }
            else if (arrayn[mid] > x)
            {
                s--;
                if (mid == end)
                    return 'f';
                end = mid - 1;
            }

        }
        if (arrayn[mid] == x)
            break;
        j++;
    }
    return 't';
}
