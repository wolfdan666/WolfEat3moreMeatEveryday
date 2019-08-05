#include <iostream>
#include <string>
using namespace std;
long long ans;
int next[1000000];
int extend[1000000];
string S, T;
int n, m;
/* 求解 T 中 next[]，注释参考 GetExtend() */
void GetNext(string & T, int & m, int next[])
{
    int a = 0, p = 0;
    next[0] = m;

    for (int i = 1; i < m; i++)
    {
        if (i >= p || i + next[i - a] >= p)
        {
            if (i >= p)
                p = i;

            while (p < m && T[p] == T[p - i])
                p++;

            next[i] = p - i;
            a = i;
        }
        else
            next[i] = next[i - a];
    }
}

/* 求解 extend[] */
void GetExtend(string & S, int & n, string & T, int & m, int extend[], int next[])
{
    int a = 0, p = 0;
    GetNext(T, m, next);

    for (int i = 0; i < n; i++)
    {
        if (i >= p || i + next[i - a] >= p) // i >= p 的作用：举个典型例子，S 和 T 无一字符相同
        {
            if (i >= p)
                p = i;

            while (p < n && p - i < m && S[p] == T[p - i])
                p++;

            extend[i] = p - i;
            a = i;
        }
        else
            extend[i] = next[i - a];
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>S;
        n = S.size();
        for(int i=1;i<n;i++){
            T = S.substr(i);
            if(i==n-1) cout<<"T: "<<T<<endl;
            m = T.size();
            GetExtend(T, m, S, n, extend, ::next);
            for (int j = 0; j < m; j++){
                cout << extend[j] << " \n"[j==m-1];
            }
            ans += extend[0]+1;
        }


        cout << ans << endl;
    }
    return 0;
}