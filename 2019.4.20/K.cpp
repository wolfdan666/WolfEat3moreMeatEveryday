// 2019年4月20日19:06:29 D题暂时放下，看k
// 数字长度要比右边的符号长度至少多出一个运算符号才行，但是 现在的问题是  如何统一 移动位置和添加
// 休息了两分钟go on,因为不能让头脑陷入混沌、
// 突然想到了统一的思路，就是   对于  数字 后面  没有符号的，直接把后面的那一部分忽视掉就行了... 也就是 从后面开始看
// 但是用什么类型的数据结构呢，就用最简单的string吧
// 2019年4月20日19:46:47 才想到i=0的时候也要采取操作  所以加上下面
                // if(i==0){ans += (fh-(num-1))<=0?0:(fh-(num-1));break;}
// 2019年4月20日19:53:48 WA了！！！
// 样例过了,但是WA,所以想特殊情况...莫名其妙...

// 2019年4月20日20:10:19 发现好像错在Swap. You can swap any two characters in the string.
// 不仅仅是相邻的，还可以是相隔的，那换个做法

// 2019年4月20日20:16:36 实验室好吵啊......绝了...自己淡定
// 2019年4月20日20:32:59 写写画画总算想出第二套方案
// 怎么还是wa了,绝了..

// 我发现我到2019年4月20日21:09:22 此刻一直致力于消耗掉所有的符号*，而没有考虑完全没有符号的情况，这种情况是特殊情况，ans=1，
// 只要插入一个*即可


// 2019年4月20日21:42:28 仔细推敲发现自己的算法还是有很多漏洞，用了错误的简单化
// 这个计算的过程本来就是顺着过去的过程，但是我的思路偏偏是逆着回来的，从顺着过去再想想
// 他这个移任意两个位归类是真的骚

// 又想到一个方案，再写，2019年4月20日22:03:25
// 2019年4月20日22:23:01  自闭了，感觉新方案操作起来很难，而且结果也很悬，算了吧，比赛自行终结吧，4小时23mins，队友4题，自己2题，GG
// 自己处在一个中等偏下的水平，因为很多大佬没有打，继续努力吧，现在悲伤也没办法
// #include<bits/stdc++.h>
// using namespace std;
// int T;
// string s;


// int main(int argc, char const *argv[])
// {
//     cin>>T;
//     while(T--) {
//         cin>>s;
//         int num=0,fh=0;
//         int ans=0;
//         int f=1; // 1 状态在收集符号的状态，0 状态在收集数字状态
//         int n = int(s.length());
//         for(int i = n-1;i>-1;i--){
//             if(f){
//                 if(s[i]=='*'){
//                     fh++;
//                 }
//                 else{
//                     f=0;  // 状态翻转
//                     num++;
//                 }
//                 if(i==0){ans += (fh-(num-1))<=0?0:(fh-(num-1));break;}
//             }
//             else{
//                 if(s[i]=='*'){
//                     if(num-1>=fh){
//                         fh=1;
//                         num=0;// 前面数字少了可以重新插入，和交换位置是相同的效果
//                     }
//                     else{
//                         ans+=(fh-(num-1));// 前面多了数字也可以通过插入符号解决
//                         fh=1;
//                         num=0;
//                     }
//                     f = 1;
//                 }
//                 else{
//                     num++;
//                 }
//                 if(i==0){ans += (fh-(num-1))<=0?0:(fh-(num-1));break;}
//             }
//         }
//         cout<<ans<<endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int T;
// string s;


// int main(int argc, char const *argv[])
// {// 讨论把所有数字当做1来讨论
//     cin>>T;
//     while(T--) {
//         cin>>s;
//         int num=0,fh=0;
//         int ans=0;
//         bool fx=0;// 是否出现过*号
//         int f=1; // 1 状态在收集符号的状态，0 状态在收集数字状态
//         int n = int(s.length());
//         for(int i = n-1;i>-1;i--){
//             if(f){
//                 if(s[i]=='*'){  // 加在后面代码处理出的1的swap后面
//                     fh++;
//                     fx=1;
//                 }
//                 else{
//                     f=0;  // 状态翻转
//                     num++;
//                 }
//                 if(i==0){ans += (fh-(num-1))<=0?0:(fh-(num-1));break;}   // 到0既可以把之前记下来的ans++全部实现(swap)，然后计算
//             }
//             else{
//                 if(s[i]=='*'){  // *1* 的类型的时候开始处理
//                     fx = 1;
//                     if(num-1>=fh){
//                         fh=1;
//                         num = num-fh;
//                     }
//                     else{
//                         fh-=(num-1);// 把此*之后的符号消化留下一个1(所以减去num-1个1)
//                         fh++;// 把此*计入
//                         num=1;
//                         ans++;// 这里的ans++是数字移动到最终的最前端，而不一定是与当下的这个*交换，这是先记账的方式
//                     }
//                     f = 1;
//                 }
//                 else{
//                     num++;
//                 }
//                 if(i==0){ans += (fh-(num-1))<=0?0:(fh-(num-1));break;}  // 到0既可以把之前记下来的ans++全部实现(swap)，然后计算
//             }
//         }
//         if(fx==0) cout<<1<<endl;
//         else cout<<ans<<endl;
//     }
//     return 0;
// }


// #include<bits/stdc++.h>
// using namespace std;
// int T;
// string s;
// string t;

// int main(int argc, char const *argv[])
// {// 讨论把所有数字当做1来讨论
//     cin>>T;
//     while(T--) {
//         cin>>s;
//         int num=0,fh=0;
//         int ans=0;
//         bool fx=0;// 是否出现过*号
//         int f=1; // 1 状态在收集符号的状态，0 状态在收集数字状态
//         int n = int(s.length());
//         for(int i=0;i<n;i++){
//             if(f){
//                 if(a[i]=='*'){
//                     fh++;
//                 }
//                 else{//(在此开始操作是以数字+符号作为一段)
//                     if(num-1>=fh){// 不够就不操作，够才操作
//                         num=1;
//                         fh=0;
//                     }
//                     else{// 不够前面那一段就不能再管了
//                         num=fh=0;
//                     }
//                     num++;
//                     f=0;
//                 }
//             }
//             else{
//                 if(a[i]=='*'){
//                     fh++;
//                     f = 1;
//                     if(i==n-1){ // 数字+符号 段都需要如下操作
//                         if(num-1>=fh){// 不够就不操作，够才操作
//                             num=1;
//                             fh=0;
//                         }
//                         else{// 不够前面那一段就不能再管了
//                             num=fh=0;
//                         }
//                         num++;
//                         f=0;
//                     }
//                 }
//                 else{
//                     num++;
//                 }
//             }
//         }
//         // 上面的第一次清洗完成了

//     }
//     return 0;
// }

/*大佬的：http://www.voidcn.com/article/p-wbqhrgdm-kh.html
 题意：给一个不带空格的逆波兰式，问最少进行几次操作，能使这个式子合法。操作有两种：
 在任意位置插入一个字符（数字或运算符），交换任意两个字符。

思路：贪心。分析一下可以知道，合法的逆波兰式数字至少比运算符多1，那么可以先通过插入让式子满足这个条件，
剩下的都用交换解决（用交换解决需要的次数不会大于插入）。对于第一步，我们可以贪心都插入在最前面；
对于第二步，我们可以贪心把最前面的运算符与最后面的数字交换。其实不需要真正执行两种操作，只需要计数就可以了。*/

#include<bits/stdc++.h>
using namespace std;

char str[1010];

int main(){
    int t;
    cin>>t;
    while(t--){
        scanf("%s",str);
        int siz=strlen(str);
        int cntn=0;
        int cnto=0;
        for(int i=0;i<siz;i++){ //统计需要插入多少个数字
            if(str[i]=='*') cnto++;
            else cntn++;
        }
        int add=0;
        if(cnto>cntn-1)add=cnto-cntn+1;
        cntn=add; cnto=0;
        int swap=0;
        for(int i=0;i<siz;i++){
            if(str[i]=='*') cnto++;
            else cntn++;
            if(cnto>cntn-1){    //如果当前不合法了,"交换"一下
                swap++;
                cnto--;
                cntn++;
            }
        }
        cout<<add+swap<<endl;
    }
    return 0;
}