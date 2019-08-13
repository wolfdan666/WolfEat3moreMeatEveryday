void add(ll &a,ll v){
    a += v;
    if(a >= mod) a-=mod;
}

void pre(){
    for(int i=0;i<M;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}