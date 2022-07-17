package main

import "fmt"

func arrayNesting_ans(nums []int) (ans int) {
	n := len(nums)
	for i := range nums {
		cnt := 0
		for nums[i] < n {
			i, nums[i] = nums[i], n
			cnt++
		}
		if cnt > ans {
			ans = cnt
		}
	}
	return
}

func arrayNesting(nums []int) int {
	// 在准备先写暴力算法的时候，在想状态标记每次修改应该比较麻烦
	// 然后想到如果一个数字已经遍历过了，那么它在那个嵌套里面的值就一直是那个值
	// 然后其他的数字看到了之前的嵌套环的话，那么就是直接把自身的cnt步数直接加上原来的环中的数
	// invalid array length sz. 数组只能用常量声明
	// var cnt [sz]int
	cnt := make([]int, len(nums))
	ans := 0
	for i := range nums {
		if cnt[i] != 0 {
			continue
		}
		tmpMap := make(map[int]bool)
		// tmp := make([]int, 0)
		tmpCnt := 0
		// 循环条件搞错了...
		// for 0 == cnt[i] {
		// fmt.Printf("debug: term new---\n")
		for !tmpMap[i] || cnt[i] != 0 {
			tmpMap[i] = true
			// tmp = append(tmp, i)
			tmpCnt++
			i = nums[i]
		}
		// fmt.Printf("debug: i: %v tmp[i]: %v\n", i, tmpMap[i])
		/*
			遍历为集合map，会导致结果混乱，所以不能用map遍历
			debug: i: 0 tmp[i]: true
			debug: index: 6
			debug: index: 2
			debug: index: 0
			debug: index: 5
			debug: ans: 8
		*/
		// for index := range tmp {
		preCnt := cnt[i]
		for index := range tmpMap {
			// fmt.Printf("debug: index: %d\n", index)
			// 之前的环值也需要加入
			// 这样加入: cnt[index] = cnt[i] + tmpCnt,不管是map还是数组，都会出问题
			cnt[index] = preCnt + tmpCnt
			if cnt[index] > ans {
				ans = cnt[index]
			}
		}
		// fmt.Printf("debug: ans: %v\n", ans)
	}
	return ans
}

func main() {
	test := []int{5, 4, 0, 3, 1, 6, 2}
	fmt.Println(arrayNesting(test))
}
