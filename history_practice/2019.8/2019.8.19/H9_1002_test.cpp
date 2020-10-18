/*
这里的重中之重是如何将有填充的线转化为无填充的先--->每个线都先*=2?
这样1->2.2->4,正好隔着一个，试试

重构代码

2019年8月19日16:22:09 才发现  乘以2面对离散化是多做了无用功！尴尬

发现由于自己太菜，然后打比赛打到后面大脑缺氧了，然后就想不清了..发现这段代码有巨大的问题！
 */

#include<bits/stdc++.h>
using namespace std;
const int M = 1e4+7;
int x1[M],x2[M],y1[M],y2[M];
bool fld[M][M];
int T,W,H,N;char tp;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

inline int compress(int *x1,int *x2,int w){
    vector<int> xs;

    for(int i=0;i<N;i++){
        for(int d=-1;d<=1;d++){
            /*虽然这里已经扩展边了,但是不能保证相邻的边是空白的,所以还是要乘以3*/
            int tx1=x1[i]+d, tx2=x2[i]+d;
            if(1<=tx1 && tx1 <= W) xs.push_back(tx1);
            if(1<=tx2 && tx2 <= W) xs.push_back(tx2);
        }
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()),xs.end());

    for(int i=0;i<N;i++){
        x1[i] = find(xs.begin(), xs.end(),x1[i]) - xs.begin();
        x2[i] = find(xs.begin(), xs.end(),x2[i]) - xs.begin();
    }
    return xs.size();
}

inline void solve(){
    /*坐标离散化*/
    W = compress(x1,x2,W);
    H = compress(y1,y2,H);

    cout<<"W: "<<W<<" H: "<<H<<endl;
    for(int i=0;i<N;i++){
        cout<<"X1: "<<x1[i]<<" Y1: "<<y1[i]<<" X2: "<<x2[i]<<" Y2: "<<y2[i]<<endl;
    }

    /*填充直线部分--y对应的是高,就是平时的行值*/
    memset(fld,0,sizeof(fld));
    for(int i=0;i<N;i++){
        for(int y=y1[i];y<=y2[i];y++){
            for(int x=x1[i];x<=x2[i];x++){
                fld[y][x] = true;
                if(fld[y][x]) cout<<1<<" "; else cout<<"s"<<0<<" ";
            }
            cout<<endl;
        }
    }

    /*求区域的个数*/
    int ans = 0;
    for(int y=0;y<H;y++){
        for(int x=0;x<W;x++){
            if(fld[y][x]) continue;
            ans++;

            /*BFS*/
            queue<pair<int,int> > que;
            que.push({x,y});
            while(!que.empty()) {
                int sx = que.front().first, sy = que.front().second;
                que.pop();

                for(int i=0;i<4;i++){
                    int tx = sx+dx[i], ty = sy+dy[i];
                    if(tx<0 || W<=tx || ty<0 || H<=ty) continue;
                    if(fld[ty][tx]) continue;
                    que.push({tx,ty});
                    fld[ty][tx] = true;
                }
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>T;
    while(T--){
        cin>>W>>H>>N;
        for(int i=0;i<N;i++){
            cin>>x1[i]>>x2[i]>>tp;
            // x1[i] *= 2; y1[i] *= 2;
            if(tp=='U'){x2[i]=x1[i]; y2[i]=H;}
            else if(tp=='D'){ x2[i]=x1[i]; y2[i]=0;}
            else if(tp=='L'){  x2[i]=0;    y2[i]=y1[i];}
            else { x2[i]=W;  y2[i]=y1[i];}
        }
        solve();
    }

    return 0;
}