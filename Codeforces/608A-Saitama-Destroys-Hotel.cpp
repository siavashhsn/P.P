#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, s;cin >> n >> s;
    int f, t;
    int time=0;
    vector<pair<int, int> > v;

    for(int i=0; i<n; i++){
        cin >> f >> t;
        v.push_back(make_pair(f, t));
    }
    sort(v.begin(), v.end());
    for(int i=v.size()-1; i>=0; i--){
        if(s>v[i].first){
            time+=s-v[i].first;
            s=v[i].first;
            i++;
        }
        else{
            if(v[i].second > time)
                time += v[i].second - time;
        }
        if(i == 0 && s != 0){
            time += s;
        }
    }
    cout << time;
    return 0;
}
