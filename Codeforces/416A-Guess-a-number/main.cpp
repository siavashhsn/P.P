#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    string s;
    char c;
    pair<pair<int, int> ,pair<char, char> > ss;
    pair<int , char> st;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        cin >> s >> m >> c;
       if(i==0)
       {
           if (c == 'Y')
           {
               if (s == ">=")
                   ss = make_pair(make_pair(m-1, 0) , make_pair('>', '/'));
               else if (s == "<=")
                   ss = make_pair(make_pair(m+1, 0) , make_pair('<', '/'));
               else if (s == "<")
                   ss = make_pair(make_pair(m, 0) , make_pair('<', '/'));
               else if (s == ">")
                   ss = make_pair(make_pair(m, 0) , make_pair('>', '/'));
            }
            else
            {
                if (s == ">=")
                    ss = make_pair(make_pair(m, 0) , make_pair('<', '/'));
                else if (s == "<=")
                    ss = make_pair(make_pair(m, 0) , make_pair('>', '/'));
                else if (s == "<")
                    ss = make_pair(make_pair(m-1, 0) , make_pair('>', '/'));
                else if (s == ">")
                    ss = make_pair(make_pair(m+1, 0) , make_pair('<', '/'));
           }
        }
        else
        {
            if (c == 'Y')
            {
                if (s == ">=")
                    st = make_pair(m-1, '>');
                else if (s == "<=")
                    st = make_pair(m+1, '<');
                else if (s == "<")
                    st = make_pair(m, '<');
                else if (s == ">")
                    st = make_pair(m, '>');
            }
            else
            {
                if (s == ">=")
                    st = make_pair(m, '<');
                else if (s == "<=")
                    st = make_pair(m, '>');
                else if (s == "<")
                    st = make_pair(m - 1, '>');
                else if (s == ">")
                    st = make_pair(m + 1, '<');
            }
            if (ss.second.first == '>' && st.second == '>') {
                if (ss.first.first < st.first)
                    ss.first.first = st.first;
                if(ss.second.second == '<') {
                    if(ss.first.first > ss.first.second) {
                        cout << "Impossible";
                        return 0;
                    }
                }
            }
            else if (ss.second.first == '<' && st.second == '<') {
                if (ss.first.first > st.first)
                    ss.first.first = st.first;
                if(ss.second.second == '>') {
                    if(ss.first.first < ss.first.second) {
                        cout << "Impossible";
                        return 0;
                    }
                }
            }
            else if (ss.second.first == '>' && st.second == '<') {
                if(ss.first.first >= st.first || ss.first.first == st.first - 1){
                    cout << "Impossible";
                    return 0;
                }
                else {
                    if(ss.first.second > st.first || (ss.first.second == 0 && flag == false)){
                        ss.first.second = st.first;
                        ss.second.second = st.second;
                        flag = true;
                    }
                }
            }
            else if (ss.second.first == '<' && st.second == '>') {
                if(ss.first.first <= st.first || ss.first.first == st.first + 1){
                    cout << "Impossible";
                    return 0;
                }
                else {
                    if(ss.first.second < st.first || (ss.first.second == 0 && flag == false)){
                        ss.first.second = st.first;
                        ss.second.second = st.second;
                        flag = true;
                    }
                }
            }
        }
    }
    if(ss.second.first == '>')
        cout << ss.first.first + 1;
    else
        cout << ss.first.first - 1;

    return 0;
}
