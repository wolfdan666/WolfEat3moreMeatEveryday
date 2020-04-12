/*
2020年4月12日16:40:54 看题
2020年4月12日16:44:48 想到暴力的想法就是直接求出两条直线的y = k*x + b的表达式，然后直接计算
2020年4月12日16:46:11 直接写一发
2020年4月12日16:56:03 发现是线段...但是还是可以这样写，就是最后判断一下是不是在线段内就行了

2020年4月12日17:06:47 感觉应该先是四边形对角判断，看看线段是否相交再求交点
2020年4月12日17:16:34 感觉被自己写成了码农题目...所以直接看答案吧
2020年4月12日18:03:13 竟然看个答案看了这么久...虽然中途自己发呆了，下面小屁孩还吵的一批，但还是自己不够专注的原因，加油吧

2020年4月12日18:23:43 学了一下第二种的思路，发现第二种代码还用了c++2.0里面的type alias 和 lambda表达式，牛逼
*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define per(i, b, a) for(int i = int(b); i >= int(a); --i)
#define mem(x, y) memset(x, y, sizeof(x))
#define SZ(x) x.size()
#define mk make_pair
#define pb push_back
#define fi first
#define se second
const ll mod=1000000007;
inline int rd(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}return x*f;}
inline ll qpow(ll a,ll b){ll ans=1%mod;for(;b;b>>=1){if(b&1)ans=ans*a%mod;a=a*a%mod;}return ans;}

// class Solution {
//     const int inf = 0x3f3f3f3f;
// public:
//     vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
//         double k1 = end1[0] == start1[0] ? inf : 1.0*(end1[1] - start1[1])/(end1[0] - start1[0]);
//         double k2 = end2[0] == start2[0] ? inf : 1.0*(end2[1] - start2[1])/(end2[0] - start2[0]);
//         vector<double> ans();

//         if( k1 == k2 ){
//             if( k1 == inf ){
//                 // 重叠了就找到重叠中最小的的x
//                 int min1 = min(start1[0],end1[0]);
//                 int max1 = max(start1[0],end1[0]);
//                 int min2 = min(start2[0],end2[0]);
//                 int max2 = max(start2[0],end2[0]);
//                 int op = max(min1,min2);
//                 if(op == start1[0] && op < max2 && op > min2) ans = start1;
//                 else if(op == end1[0] && op < max2 && op > min2) ans = end1;
//                 else if(op == start2[0] && op < max1 && op > min1) ans = start2;
//                 else if(op < max1 && op > min1) ans = end2;
//             } else {
//                 double b1 =
//             }
//         }
//     }
// };

class Solution {
public:
    // 判断 (xk, yk) 是否在「线段」(x1, y1)~(x2, y2) 上
    // 这里的前提是 (xk, yk) 一定在「直线」(x1, y1)~(x2, y2) 上
    bool inside(int x1, int y1, int x2, int y2, int xk, int yk) {
        // 若与 x 轴平行，只需要判断 x 的部分
        // 若与 y 轴平行，只需要判断 y 的部分
        // 若为普通线段，则都要判断
        return (x1 == x2 || (min(x1, x2) <= xk && xk <= max(x1, x2))) && (y1 == y2 || (min(y1, y2) <= yk && yk <= max(y1, y2)));
    }

    void update(vector<double>& ans, double xk, double yk) {
        // 将一个交点与当前 ans 中的结果进行比较
        // 若更优则替换
        if (!ans.size() || xk < ans[0] || (xk == ans[0] && yk < ans[1])) {
            ans = {xk, yk};
        }
    }

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int x1 = start1[0], y1 = start1[1];
        int x2 = end1[0], y2 = end1[1];
        int x3 = start2[0], y3 = start2[1];
        int x4 = end2[0], y4 = end2[1];

        vector<double> ans;
        // 判断 (x1, y1)~(x2, y2) 和 (x3, y3)~(x4, y3) 是否平行
        if ((y4 - y3) * (x2 - x1) == (y2 - y1) * (x4 - x3)) {
            // 若平行，则判断 (x3, y3) 是否在「直线」(x1, y1)~(x2, y2) 上
            if ((y2 - y1) * (x3 - x1) == (y3 - y1) * (x2 - x1)) {
                // 判断 (x3, y3) 是否在「线段」(x1, y1)~(x2, y2) 上
                if (inside(x1, y1, x2, y2, x3, y3)) {
                    update(ans, (double)x3, (double)y3);
                }
                // 判断 (x4, y4) 是否在「线段」(x1, y1)~(x2, y2) 上
                if (inside(x1, y1, x2, y2, x4, y4)) {
                    update(ans, (double)x4, (double)y4);
                }
                // 判断 (x1, y1) 是否在「线段」(x3, y3)~(x4, y4) 上
                if (inside(x3, y3, x4, y4, x1, y1)) {
                    update(ans, (double)x1, (double)y1);
                }
                // 判断 (x2, y2) 是否在「线段」(x3, y3)~(x4, y4) 上
                if (inside(x3, y3, x4, y4, x2, y2)) {
                    update(ans, (double)x2, (double)y2);
                }
            }
            // 在平行时，其余的所有情况都不会有交点
        }
        else {
            // 联立方程得到 t1 和 t2 的值
            double t1 = (double)(x3 * (y4 - y3) + y1 * (x4 - x3) - y3 * (x4 - x3) - x1 * (y4 - y3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
            double t2 = (double)(x1 * (y2 - y1) + y3 * (x2 - x1) - y1 * (x2 - x1) - x3 * (y2 - y1)) / ((x4 - x3) * (y2 - y1) - (x2 - x1) * (y4 - y3));
            // 判断 t1 和 t2 是否均在 [0, 1] 之间
            if (t1 >= 0.0 && t1 <= 1.0 && t2 >= 0.0 && t2 <= 1.0) {
                ans = {x1 + t1 * (x2 - x1), y1 + t1 * (y2 - y1)};
            }
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/intersection-lcci/solution/jiao-dian-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution2 {
public:
    using Coor = vector <double>;
    static constexpr double EPS = 1E-6;

    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int ax = start1[0], ay = start1[1], bx = end1[0], by = end1[1];
        int cx = start2[0], cy = start2[1], dx = end2[0], dy = end2[1];
        int acx = cx - ax, acy = cy - ay, abx = bx - ax, aby = by - ay, adx = dx - ax, ady = dy - ay;
        int cax = ax - cx, cay = ay - cy, cbx = bx - cx, cby = by - cy, cdx = dx - cx, cdy = dy - cy;
        // 叉积运算
        auto cross = [] (int ux, int uy, int vx, int vy) {
            return ux * vy - vx * uy;
        };
        // 判断线段 (ux, uy) -- (vx, vy) 是否包含 (mx, my)
        auto bothSide = [&] (int mx, int my, int ux, int uy, int vx, int vy) {
            double um = sqrt((ux - mx) * (ux - mx) + (uy - my) * (uy - my));
            double vm = sqrt((vx - mx) * (vx - mx) + (vy - my) * (vy - my));
            double uv = sqrt((vx - ux) * (vx - ux) + (vy - uy) * (vy - uy));
            return (ux - mx) * (vx - mx) <= 0 && (uy - my) * (vy - my) <= 0;
        };
        // 以 x 为第一关键字，y 为第二关键字比较两个点的大小
        auto cmp = [] (const Coor& u, const Coor& v) {
            if (u.size() == 0 || v.size() == 0) return v.size() == 0;
            return (u[0] != v[0]) ? (u[0] < v[0]) : (u[1] < v[1]);
        };
        // 共线处理和 T 形处理
        if (cross(cax, cay, cbx, cby) == 0 || cross(adx, ady, abx, aby) == 0) {
            bool aInCd = bothSide(ax, ay, cx, cy, dx, dy), bInCd = bothSide(bx, by, cx, cy, dx, dy);
            bool cInAb = bothSide(cx, cy, ax, ay, bx, by), dInAb = bothSide(dx, dy, ax, ay, bx, by);
            Coor ans;
            if (aInCd) ans = min(ans, Coor({(double)ax, (double)ay}), cmp) ;
            if (bInCd) ans = min(ans, Coor({(double)bx, (double)by}), cmp);
            if (cInAb) ans = min(ans, Coor({(double)cx, (double)cy}), cmp);
            if (dInAb) ans = min(ans, Coor({(double)dx, (double)dy}), cmp);
            return ans;
        }
        // 判断两条线段是否有公共点
        auto intersect = [&] () {
            return cross(acx, acy, abx, aby) * cross(adx, ady, abx, aby) <= 0 && cross(cax, cay, cdx, cdy) * cross(cbx, cby, cdx, cdy) <= 0;
        };
        if (!intersect()) {
            return Coor();
        }
        // 计算三角形 PQM 的面积
        auto getArea = [&] (int px, int py, int qx, int qy, int mx, int my) -> double {
            int mpx = px - mx, mpy = py - my, mqx = qx - mx, mqy = qy - my;
            return fabs(double(0.5) * cross(mpx, mpy, mqx, mqy));
        };
        // 定比分点
        double ck = getArea(ax, ay, bx, by, cx, cy), dk = getArea(ax, ay, bx, by, dx, dy);
        double k = ck / dk;
        double rx = (cx + k * dx) / (1 + k), ry = (cy + k * dy) / (1 + k);
        return Coor({rx, ry});
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/intersection-lcci/solution/jiao-dian-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main(){


    return 0;
}