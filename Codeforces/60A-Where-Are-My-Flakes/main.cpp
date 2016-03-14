#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    size_t n, m, a;
    string s1, s2, s3, s4;
    vector<pair<string, int> > vs;
    vs.push_back(make_pair("V", 0));
    vector<pair<char, char> > vb;
    vb.push_back(make_pair('N', 'M'));
    cin >> n >> m;
    for (size_t i = 0; i < m; ++i) {
        cin >> s1 >> s2 >> s3 >> s4 >> a;
        vs.push_back(make_pair(s3, a));
    }
    for (size_t i = 0; i < n; ++i) {
        vb.push_back(make_pair('N', 'M'));
    }
    size_t i=1, j=0,ans=0;
    char c;
    while (i <= m)
    {
        if(vs[i].first == "left" || vs[i].first == "l")
        {
            if(vb[vs[i].second - 1].first ==  'V' && vb[vs[i].second - 1].second ==  'R' || vs[i].second == 1)
            {
                cout << -1;
                return 0;
            }
            else
            {
                vb[vs[i].second].first = 'V';
                vb[vs[i].second].second =  'L';
                c = 'L';
                j = vs[i].second;
                i++;
            }
        }
        else if(vs[i].first == "right" || vs[i].first == "r")
        {
            if(vb[vs[i].second + 1].first ==  'V' && vb[vs[i].second + 1].second ==  'L' || vs[i].second == n)
            {
                cout << -1;
                return 0;
            }
            else
            {
                vb[vs[i].second].first = 'V';
                vb[vs[i].second].second =  'R';
                c = 'R';
                j = vs[i].second;
                i++;
            }
        }
    }
    bool flag= false;
    if(c=='L')
    {
        for (size_t var = j-1; var > 0; --var) {
            if(vb[var].first == 'N')
            {
                flag=true;
                ans++;
            }
            else if (vb[var].second == 'L') ans=0;
            else if(flag==true && vb[var].second == 'R') break;
        }
    }
    else
    {
        for (size_t var = j + 1; var <= n; ++var) {
            if(vb[var].first == 'N')
            {
                flag=true;
                ans++;
            }
            else if (vb[var].second == 'R') ans=0;
            else if (flag==true && vb[var].second == 'L') break;
        }
    }
    cout << ans;

    return 0;
}
