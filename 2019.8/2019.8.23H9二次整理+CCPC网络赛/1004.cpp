
花朝十九 2019/8/23 16:52:37
#include <bits/stdc++.h>

#define IL inline

#define R register

#define var long long

#define I 50010

using namespace std;



template < typename T > IL void of (R T &a) {

    R char c=getchar (); R T w=1, p=0;

    while (!isdigit (c)) { if (c=='-') w=-1; c=getchar (); }

    while (isdigit (c)) { p=p*10+c-'0'; c=getchar (); }

    a=w*p;

}



template < typename T > IL void Sma (R T &a,R T b) { a>b?a=b:0; }

template < typename T > IL void Big (R T &a,R T b) { a<b?a=b:0; }



/* -------------------- wuzhoupei -------------------- */



int n,m,q,tot,s,t,T;

int head[I], len[250100], ss[I], mi[I];



struct K1 {

    int x; var w;

    friend bool operator < (K1 a1,K1 a2) {

        return a1.w>a2.w;

    }

} ;

priority_queue <K1> Q1, Q2;



struct K2 {

    var w;

    friend bool operator < (K2 a1,K2 a2) {

        return a1.w<a2.w;

    }

} ;

priority_queue <K2> Q3;

//queue <int> Q;



struct edge { int to,up; var w; } aa[I*2];

IL void A (int x,int y,var z) {

    aa[++tot]=(edge) {y,head[x],z};

    head[x]=tot;

}



//IL void S () {

//  for (int i=s;i<=t;i++) dis[i]=1e18;

//  dis[s]=0; Q.push (s); inq[s]=1;

//

//  while (!Q.empty ()) {

//      R int x=Q.front (); Q.pop (); inq[x]=0;

//      for (int i=head[x],go;i;i=aa[i].up)

//      {

//          if (!(i&1)) {

//              go=aa[i].to;

//              if (dis[go]>dis[x]+aa[i].w) {

//                  dis[go]=dis[x]+aa[i].w;

//                  if (!inq[go]) {

//                      Q.push (go);

//                      inq[go]=1;

//                  }

//              }

//          }

//      }

//  }

//}



IL void AS (int k) {

    int nu=0; var lim=0;



    Q1.push ((K1) {s,0});



    while (!Q1.empty ()) {

        R K1 x=Q1.top (); Q1.pop ();

        if (Q3.size ()>=k && x.w+mi[x.x]>=Q3.top ().w) continue ;



        for (int i=head[x.x],go;i;i=aa[i].up)

        {

            go=aa[i].to;



            if (Q3.size ()<k) {

                if (x.w+aa[i].w>0) Q3.push ((K2) {x.w+aa[i].w});

                Q1.push ((K1) {go,x.w+aa[i].w});

            } else {

                if (x.w+aa[i].w>Q3.top ().w) {

                    continue ;

                }

                Q1.push ((K1) {go,x.w+aa[i].w});

                Q3.push ((K2) {x.w+aa[i].w});

                Q3.pop ();

            }

        }

    }

}



int main ()

{

//  freopen ("1.txt","r",stdin);



    of (T);

    while (T --) {

        of (n); of (m); of (q);

        s=0; t=n+1;



        for (int i=s;i<=t;i++) head[i]=0;

        tot=0;


        for (int i=1;i<=n;i++){
            mi[i]=1e9;
            A (s,i,0);
        }
        for (int i=1;i<=m;i++){
            int x,y; var z;
            of (x); of (y); of (z);
            A (x,y,z);
            Sma (mi[x],(int) z);
        }
        int now=0;
        for (int i=1;i<=q;i++) {
            of (ss[i]);
            Big (now,ss[i]);
        }
        AS (now);
        while (Q3.size ()>now) Q3.pop ();

        for (int i=now;i;i--) {

            len[i]=Q3.top ().w;
            Q3.pop ();
        }
        for (int i=1;i<=q;i++) printf ("%d\n",len[ss[i]]);
    }
    return 0;

}