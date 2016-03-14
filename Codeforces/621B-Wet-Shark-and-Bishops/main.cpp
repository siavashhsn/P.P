#include <bits/stdc++.h>
using namespace std;

bool a[1001][1001]={0};

vector<pair<int, pair<int,bool> > > v, vv;

int main()
{
    int n, x, y;cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        v.push_back(make_pair(x,make_pair(y,0)));
        vv.push_back(make_pair(y,make_pair(x,0)));
    }

    long long sum=0, a=1, q, p;

    sort(v.begin(), v.end());

    for (size_t i = 0; i < v.size(); ++i) {
        if(v[i].second.second == 0){
            //v[i].second.second = 1;
            p=v[i].first+1;
            q=v[i].second.first+1;
            for (size_t j = i+1; j < v.size(); ++j) {
                if(v[j].first > p) {
                    p += v[j].first-p;
                    q += v[j].first-p;
                }
                if(v[j].second.second == 0) {
                    if (p == v[j].first && q == v[j].second.first) {
                        a++;
                        p++;
                        q++;
                        v[j].second.second = 1;
                    }

                }
            }
        }
        if(a>=2) {
            int aa=0;
            for (int j = 1; j < a ; ++j) {
                aa += a-j;
            }
            sum += aa;
            a=1;
        }
    }

    sort(vv.begin(), vv.end());
    a=1;

    for (size_t i = 0; i < vv.size(); ++i) {
        if(vv[i].second.second == 0){
            //vv[i].second.second = 1;
            p=vv[i].first+1;
            q=vv[i].second.first+1;
            for (size_t j = i+1; j < vv.size(); ++j) {
                if(vv[j].second.second == 0) {
                    if (p == vv[j].first && q == vv[j].second.first) {
                        a++;
                        p++;
                        q++;
                        vv[j].second.second = 1;
                    }
                }
                else if(vv[j].first > p) {
                    p += vv[j].first-p;
                    q += vv[j].first-p;
                }
            }
        }
        if(a>=2) {
            int aa=0;
            for (int j = 1; j < a ; ++j) {
                aa += a-j;
            }
            sum += aa;
            a=1;
        }
    }

    cout << sum;
    return 0;
}
