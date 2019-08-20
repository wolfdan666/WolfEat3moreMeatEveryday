int wa[maxn],wb[maxn],wv[maxn],ws[maxn];

/*r为字符串数组,sa是后缀数组,n为字符串长度,m为字符种类数*/
void da(int *r,int *sa,int n,int m){
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;

    for(j=1,p=1;p<n;j*=2,m=p){
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;

        /*这一行oi-wiki没有,不知道有什么用*/
        for(i=0;i<n;i++) wv[i]=x[y[i]];

        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];

        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&r[sa[i-1]+j]==r[sa[i]+j])?p-1:p++;
    }
    return;
}



/*LCP:最长公共字串部分*/
int rank[maxn],height[maxn];

/*r为字符串数组,sa是后缀数组,n为字符串长度*/
void calheight(int *r,int *sa,int n){
    int i,j,k=0;
    /*用sa[]得到rank[]*/
    for(i=1;i<=n;i++) rank[sa[i]]=i;
    /*j就是后缀i的前一名的后缀位置,然后如果前一个串之间有k,那么就从k--起步*/
    for(i=0;i<n;height[rank[i++]]=k)
    for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return;
}