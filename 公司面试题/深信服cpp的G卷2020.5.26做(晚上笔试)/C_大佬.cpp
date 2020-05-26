#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  int f=0x3f3f3f3f,res=INT_MAX;
  for(int i=0;i<T;i++) {
    int d;
    scanf("%d",&d);
    res=min(res,f=min(d,f+d));
  }
  cout << res << endl;
  return 0;
}