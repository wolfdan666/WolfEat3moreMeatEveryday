package main

import (
	"fmt"
	"math"
)

/*
ans_v: 4
ans_v: 3
ans_v: 3
8

完了，路径上的去重没有去掉...
可以直接来一个路径集合，这样就可以去重了
map[i*nLen + j]bool, 需要深拷贝路径数组，好像有点丑...而且go中数组传递好像只有传指针，还要自己重新申请一下内存

是一种思路，但是感觉答案可能不一样，搞了一小时了，还是看答案吧...

答案用了巧妙的状态设计，让相同的格子直接是x1 = x2,从而简化了状态的存储

**而且只能从终点回起点一次，所以我上面的想法的答案是无限次，是不行的**

设两人的坐标为 (x_1,y_1)和 (x_2,y_2)，则 x_1+y_1 = x_2+y_2 = k。那么当 x_1=x_2x时，必然有 y_1=y_2y，即两个人到达了同一个格子。
定义 f[k][x_1][x_2] 表示两个人（设为 A 和 B）分别从 (x_1,k-x_1))和(x_2,k−x_2) 同时出发，到达 (N-1,N-1)(N−1,N−1) 摘到的樱桃个数之和的最大值。
作者：LeetCode-Solution
链接：https://leetcode.cn/problems/cherry-pickup/solution/zhai-ying-tao-by-leetcode-solution-1h3k/

其中比较难理解的东西: x1 := max(k-n+1, 0)
x1 + y1 = n
如果 x1 < k - (n - 1), 那么 x1 < (x1 + y1) - (n - 1), (n - 1) < y1, 所以 x1 不能 小于 k-n+1
*/
func cherryPickupMy(grid [][]int) int {
	nLen := len(grid)
	ans := make([]int, 0, 5)
	var dfs func(_grid [][]int, cnt, i, j int)
	dfs = func(_grid [][]int, cnt, i, j int) {
		// 非法终止条件
		// panic, index out of range
		// if -1 == _grid[i][j] {
		if nLen == i || nLen == j || -1 == _grid[i][j] {
			return
		}

		// 判断当前值
		cnt += _grid[i][j]

		// 答案终止条件
		if i == nLen-1 && j == nLen-1 {
			ans = append(ans, cnt)
			return
		}

		// dfs链路
		dfs(_grid, cnt, i+1, j)
		dfs(_grid, cnt, i, j+1)
	}

	// 运行计算
	dfs(grid, 0, 0, 0)

	ansLen := len(ans)
	if ansLen == 0 {
		return 0
	}
	ansInt := 0
	for _, v := range ans {
		fmt.Printf("ans_v: %d\n", v)
		ansInt += v
	}

	// 起始点不为-1，但要判断去重 `(起点为1 + 终点为1)*(结果数 - 1)`
	ansInt -= (grid[0][0] + grid[nLen-1][nLen-1]) * (nLen - 1)
	return ansInt
}

func cherryPickup(grid [][]int) int {
	n := len(grid)
	f := make([][]int, n)
	for i := range f {
		f[i] = make([]int, n)
		for j := range f[i] {
			f[i][j] = math.MinInt32
		}
	}
	f[0][0] = grid[0][0]
	// k = 1, 先更新 向下向右走了一步的情况
	for k := 1; k < n*2-1; k++ {
		/*
			其中比较难理解的东西: x1 := max(k-n+1, 0)
			x1 + y1 = n
			如果 x1 < k - (n - 1),
			那么 x1 < (x1 + y1) - (n - 1), (n - 1) < y1
			所以 x1 不能 小于 k-n+1
		*/
		for x1 := min(k, n-1); x1 >= max(k-n+1, 0); x1-- {
			for x2 := min(k, n-1); x2 >= x1; x2-- {
				y1, y2 := k-x1, k-x2
				if grid[x1][y1] == -1 || grid[x2][y2] == -1 {
					f[x1][x2] = math.MinInt32
					continue
				}
				res := f[x1][x2] // 都往右
				if x1 > 0 {
					res = max(res, f[x1-1][x2]) // 往下，往右
				}
				if x2 > 0 {
					res = max(res, f[x1][x2-1]) // 往右，往下
				}
				if x1 > 0 && x2 > 0 {
					res = max(res, f[x1-1][x2-1]) // 都往下
				}
				res += grid[x1][y1]
				if x2 != x1 { // 避免重复摘同一个樱桃
					res += grid[x2][y2]
				}
				f[x1][x2] = res
			}
		}
	}
	return max(f[n-1][n-1], 0)
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}

func main() {
	grid := [][]int{{0, 1, -1},
		{1, 0, -1},
		{1, 1, 1}}
	fmt.Println(cherryPickup(grid))
}
