#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string.h>

using namespace std;

typedef vector<double> v_d;

struct Q
{
    double Q1,Q3;
};

vector<double> v;

/**
 * @brief sToi convert string to double
 * @param s the input string
 * @return the number
 */
double sToi(string s)
{
    double ans=0;
    int pointplace=0;
    bool f=0;
    for(size_t i=0; i<s.length(); i++)
    {
        if(s[i] != '.'){
            ans *= 10;
            ans += (s[i]-48);
            if(f==1)
                pointplace++;
        }
        else
            f=1;
    }
    ans = ans/(pow(10,pointplace));
    return ans;
}

/**
 * @brief median calculate median
 * @param vv the numbers array
 * @return double the number
 */
double median(const vector <double>& vv)
{
    if(vv.size()%2 == 0)
        return (vv[(vv.size()/2) - 1]+vv[(vv.size()/2)])/2;
    else
        return vv[(vv.size())/2];
}

/**
 * @brief quartil this function calculate range of quartils and give it to the median function
 * @return double  Q1, Q3
 */
Q quartil()
{
    Q qur;
    vector <double> vv;
    // if range of main numbers array is even then this part will be execute
    if(v.size()%2 == 0)
    {
        for(size_t i=0; i <= v.size()/2-1; i++)
            vv.push_back(v[i]);

        qur.Q1 = median(vv);
        vv.clear();

        for(size_t i=v.size()/2; i < v.size(); i++)
            vv.push_back(v[i]);

        qur.Q3 = median(vv);
    }
    // else do this
    else
    {
        vv.clear();
        for(size_t i=0; i < v.size()/2; i++)
            vv.push_back(v[i]);

        qur.Q1 = median(vv);
        vv.clear();

        for(size_t i=v.size()/2+1; i < v.size(); i++)
            vv.push_back(v[i]);

        qur.Q3 = median(vv);
    }
    return qur;
}


int main()
{
    string s,ss;
    vector<double> outlier;
    double min, max;

    getline(cin,s);

    // separate string and give it to the stoi function
    // to convert it to the integer
    for(size_t i=0; i<s.length(); i++){
        if(s[i] == ',' || s[i] == ' '){
            v.push_back(sToi(ss));
            ss="";
        }
        else
            ss+=s[i];
    }

    v.push_back(sToi(ss));

    // sort main number array
    sort(v.begin(),v.end());

    Q qq = quartil();

    // calculate max range of drop box
    double
        qmin = qq.Q1 - 1.5*(qq.Q3-qq.Q1),
        qmax = qq.Q3 + 1.5*(qq.Q3-qq.Q1);

    // check if numbers is outlier or not
    for (size_t i = 0; i < v.size(); ++i) {
        if(v[i] < qmin || v[i] > qmax)
            outlier.push_back(v[i]);
    }

    min = v[0];
    max = v[v.size()-1];

    // print boxplot numbers
    cout
        << fixed
        << "min: "<< setprecision(2) << min << endl
        << "Q1: " << setprecision(2) << qq.Q1 << endl
        << "Q2: " << setprecision(2) << median(v) <<endl
        << "Q3: " << setprecision(2) << qq.Q3 << endl
        << "max: "<< setprecision(2) << max << endl;

    // print outlier numbers
    if(!outlier.empty()) {
        cout << "outlier: ";
        for(size_t i=0; i < outlier.size(); i++)
            cout << setprecision(2) << outlier[i] << " ";
    }
    else
        cout << "outlier: no outlier" << endl;
    return 0;
}
