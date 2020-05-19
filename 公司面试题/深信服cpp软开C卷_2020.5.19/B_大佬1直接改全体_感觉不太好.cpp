#include <bits/stdc++.h>
using namespace std;

typedef long long ll ;
typedef unsigned long long ull ;

int unescape_c_quoted(string& s, const string& str)
{
    if(str.front() != '\"' || str.back() != '\"') return -1;
    for (int i = 0; i < str.size(); ++i)
    {
        if(str[i] == '\"') continue;
        if(str[i] == '\\')
        {
            if(i + 1 >= str.size()) return -1;
            if(str[i+1] == '\\')
            {
                s += '\\';
            }
            else if(str[i+1] == 'n')
            {
                s += '\n';
            }
            else if(str[i+1] == '\"')
            {
                s += '\"';
            }
            else if(str[i+1] == 'r')
            {
                s += '\r';
            }
            else if(str[i+1] == '\'')
            {
                s += '\'';
            }
            else if(str[i+1] == 't')
            {
                s += '\t';
            }
            i++;
        }
        else s += str[i];
    }
    return 0;
}

int main()
{
    string str;
    getline(cin, str);
    string s;
    int ret = unescape_c_quoted(s, str);
    if(ret > -1) printf("%s\n", s.c_str());
    else printf("error\n");
    return 0;
}