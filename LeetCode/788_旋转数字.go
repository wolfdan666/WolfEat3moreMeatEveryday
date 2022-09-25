package main

import "strconv"

var check = [10]int{0, 0, 1, -1, -1, 1, 1, -1, 0, 1}

/*
rotatedDigits 获取N内多少个好数(180度旋转还能是数字并且不为自己).
感觉以前做过类似的，使用规律计算加二分。这里的规律好像是排列组合，然后抛除一些不好的。

看了一下答案，发现理解错题意了，是每个数字都旋转，不是直接整体旋转...
因此简单很多很多... 可以直接暴力法.
*/
func rotatedDigits(n int) (ans int) {
	for i := 1; i <= n; i++ {
		valid, diff := true, false
		for _, c := range strconv.Itoa(i) {
			if check[c-'0'] == -1 {
				valid = false
			} else if check[c-'0'] == 1 {
				diff = true
			}
		}
		if valid && diff {
			ans++
		}
	}
	return
}

/*
也可以数位dp.
作者：LeetCode-Solution
链接：https://leetcode.cn/problems/rotated-digits/solution/xuan-zhuan-shu-zi-by-leetcode-solution-q9bh/
*/
func rotatedDigitsDP(n int) int {
	digits := strconv.Itoa(n)
	memo := [5][2][2]int{}
	for i := 0; i < 5; i++ {
		memo[i] = [2][2]int{{-1, -1}, {-1, -1}}
	}
	var dfs func(int, bool, bool) int
	dfs = func(pos int, bound, diff bool) (res int) {
		if pos == len(digits) {
			return bool2int(diff)
		}
		ptr := &memo[pos][bool2int(bound)][bool2int(diff)]
		if *ptr != -1 {
			return *ptr
		}
		lim := 9
		if bound {
			lim = int(digits[pos] - '0')
		}
		for i := 0; i <= lim; i++ {
			if check[i] != -1 {
				res += dfs(pos+1, bound && i == int(digits[pos]-'0'), diff || check[i] == 1)
			}
		}
		*ptr = res
		return
	}
	return dfs(0, true, false)
}

func bool2int(b bool) int {
	if b {
		return 1
	}
	return 0
}
