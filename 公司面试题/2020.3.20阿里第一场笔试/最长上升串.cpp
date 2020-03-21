#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std ;

int n ;

struct node {
    char first , last ;
    int len ;
} ;

int g[26][26] ;

int dp[26] ;


int main() {

    cin >> n ;
    vector<node> strs ;
    for (int i = 0 ; i < n ; ++i) {
        node state ;
        string t ;
        cin >> t ;
        state.first = t[0] ;
        state.last = t[t.length() - 1] ;
        state.len = t.length() ;
        strs.push_back(state) ;
        if (state.first == state.last) {
            g[state.first - 'a'][state.last - 'a'] += t.length() ;
        } else {
            g[state.first - 'a'][state.last - 'a'] = max(g[state.first - 'a'][state.last - 'a'] , int(t.length())) ;
        }
    }

    dp[0] = g[0][0] ;

    for (int i = 1 ; i < 26 ; ++i) {
        int t = g[i][i] ;

        for (int j = 0 ; j < i ; ++j) {
            dp[i] = max(dp[i] , dp[j] + g[j][i]) ;
        }
        dp[i] += t ;
    }

    int res = 0 ;

    for (int i = 0 ; i < 26 ; ++i) {
        res = max(res , dp[i]) ;
    }

    printf("%d\n",res) ;

    return 0 ;
}