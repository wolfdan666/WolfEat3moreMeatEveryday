#include<bits/stdc++.h>
using namespace std;
#define random(a,b) ((a)+rand()%((b)-(a)+1))
stringstream ss;
int main( int argc, char *argv[] ){
	int seed=time(NULL);
	if(argc){
		ss.clear();
		ss<<argv[1];
		ss>>seed;
	}
	srand(seed);
	int n = 7,m = 15;
	cout<<n<<" "<<m<<endl;
	while(n--){
		int tmp = rand()%10,tp = rand()%100;
		if(!tmp) tmp++;
		if(!tp) tp++;

		cout<<tmp<<" "<<tp<<endl;
	}
    return 0;
}
