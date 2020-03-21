#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstdio>
#include <cstring>
#include <stack>
#include <map>
#include <unordered_map>

using namespace std ;

vector<int> a ;

map<vector<int> , int> dp ;

int dfs(vector<int> &temp) {
    if (dp.find(temp) != dp.end())
        return dp[temp] ;
    bool finish = true ;
    for (int i = 0 ; i < 10 ; ++i) {
        if (temp[i] != 0)
            finish = false ;
    }
    if (finish == true) {
        dp[temp] = 0 ;
        return 0 ;
    }
    int state = -1 ;
    for (int i = 0 ; i < 10 ; ++i) {
        if (temp[i] > 0) {
            state = i ;
            break ;
        }
    }
    int res = 0x7f7f7f ;
    //case1
    temp[state] -= 1 ;
    res = min(res , dfs(temp) + 1) ;
    temp[state] += 1 ;
    //case2
    if (temp[state] >= 2) {
        temp[state] -=2 ;
        res = min(res , dfs(temp) + 1) ;
        temp[state] += 2 ;
    }
    //case3
    if (state + 4 < 10) {
        bool test = true ;
        for (int j = state ; j <= state + 4 ; ++j) {
            if (temp[j] == 0) {
                test = false ;
                break ;
            }
        }
        if (test) {
            for (int j = state ; j <= state + 4 ; ++j) {
                temp[j] -= 1 ;
            }
            res = min(res , dfs(temp) + 1) ;
            for (int j = state ; j <= state + 4 ; ++j) {
                temp[j] += 1 ;
            }
        }
    }
    //case4
    if (state + 2 < 10) {
        bool test = true ;
        for (int j = state ; j <= state + 2 ; ++j) {
            if (temp[j] < 2) {
                test = false ;
                break ;
            }
        }
        if (test) {
            for (int j = state ; j <= state + 2 ; ++j) {
                temp[j] -= 2 ;
            }
            res = min(res , dfs(temp) + 1) ;
            for (int j = state ; j <= state + 2 ; ++j) {
                temp[j] += 2 ;
            }
        }
    }

    dp[temp] = res ;
    return res ;

}

int main() {

    int n = 10 ;
    a = vector<int> (10 , 0) ;

    for (int i = 0 ; i < 10 ; ++i) {
        scanf("%d",&a[i]) ;
    }

    int res = dfs(a) ;

    printf("%d\n",res) ;

    return 0 ;
}