package main

import (
	"fmt"
	"math"
	"strconv"
)

/*
通过测试用例：
24 / 39
输入：
230241
输出：
231240
预期结果：
230412

2022年07月03日19:36 这个例子，让我的逆序对算法直接是错的，因为换了3个数，所以可能枚举排列再排序？
*/

// func nextGreaterElement(n int) int {
// 	words := []byte(strconv.Itoa(n))
// 	nLen := len(words)
// 	for i := nLen - 1; i >= 1; i-- {
// 		for j := i - 1; j >= 0; j-- {
// 			if words[i] > words[j] {
// 				words[i], words[j] = words[j], words[i]
// 				ans_s := string(words)
// 				ans, err := strconv.Atoi(ans_s)
// 				if err != nil {
// 					fmt.Println("Atoi error")
// 					return -1
// 				}
// 				return ans
// 			}
// 		}
// 	}
// 	return -1
// }

func nextGreaterElement(n int) int {
	nums := []byte(strconv.Itoa(n))
	i := len(nums) - 2
	for i >= 0 && nums[i] >= nums[i+1] {
		i--
	}
	if i < 0 {
		return -1
	}

	j := len(nums) - 1
	for j >= 0 && nums[i] >= nums[j] {
		j--
	}
	nums[i], nums[j] = nums[j], nums[i]
	reverse(nums[i+1:])
	ans, _ := strconv.Atoi(string(nums))
	if ans > math.MaxInt32 {
		return -1
	}
	return ans
}

func reverse(a []byte) {
	for i, n := 0, len(a); i < n/2; i++ {
		a[i], a[n-1-i] = a[n-1-i], a[i]
	}
}

// 作者：LeetCode-Solution
// 链接：https://leetcode.cn/problems/next-greater-element-iii/solution/xia-yi-ge-geng-da-yuan-su-iii-by-leetcod-mqf1/

func main() {
	n := 12
	fmt.Println(nextGreaterElement(n))
	n = nextGreaterElement(n)
	fmt.Println(nextGreaterElement(n))
}
