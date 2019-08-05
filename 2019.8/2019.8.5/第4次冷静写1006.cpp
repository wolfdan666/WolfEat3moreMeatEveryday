#include <iostream>
#include <string>
using namespace std;
long long ans;
// int next[1000000];
int nxt[1000000];
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
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ans = 0;
        cin>>S;
        n = S.size();
        T = S.substr(1);
        m = n - 1;
        /*可能程序以为我用了前面的函数声明中的next[],所以说我模棱两可,加个全局的命名空间就行
        或者换个变量名也行*/
        // GetExtend(T, m, S, n, extend, ::next);
        GetExtend(T, m, S, n, extend, nxt);
        for (int j = 0; j < m; j++){
            // cout << extend[j] << " \n"[j==m-1];
            ans += extend[j]+j==n-1 ? extend[j] : extend[j]+1 ;
        }


        cout << ans << endl;
    }
    return 0;
}