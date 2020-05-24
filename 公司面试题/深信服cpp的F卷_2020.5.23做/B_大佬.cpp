#include <iostream>

using namespace std;
/*
    x=(v1*b2-b1*v2)/(a1*b2-b1*a2);
    y=(v1*a2-a1*v2)/(b1*a2-a1*b2);
*/
int main()
{
    int T;
    long long a1,b1,v1,a2,b2,v2;
    long long q,w,e,r;
    cin>>T;
    while(T--){
        cin>>a1>>b1>>v1>>a2>>b2>>v2;
        q=v1*b2-b1*v2;
        w=a1*b2-b1*a2;
        e=v1*a2-a1*v2;
        r=b1*a2-a1*b2;
        // if(q%w == 0) cout<<"T:"<<q/w<<endl;
        // if(e%r == 0) cout<<"T:"<<e/r<<endl;
        if((w==0)||(r==0)||(q%w)||(e%r)||(q/w <0 )||(e/r < 0)){
            cout<<"UNKNOWN"<<endl;
            continue;
        }
        cout<<q/w<<" "<<e/r<<endl;
    }
    return 0;
}