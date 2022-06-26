package main

import (
	"fmt"
	"math/rand"
	"sort"
)

/*
执行结果：
解答错误
显示详情
添加备注

通过测试用例：
49 / 68
输入：
["Solution","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick","pick"]
[[4,[2,1]],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[],[]]
输出：
[null,1,0,0,0,0,0,0,0,0,1,0,0,1,1,1,1,1,1,0,1,0,1,0,0,1,1,0,0,0,1]
预期结果：
[null,3,0,0,3,0,0,3,3,3,3,0,0,3,3,3,3,3,0,0,3,3,3,0,0,0,0,3,3,3,3]
*/

/*
66 / 68 个通过测试用例
状态：执行出错
提交时间：几秒前
执行出错信息：

[[1000000000,[640145908]]...构造了一个超级大数...导致我不能重新构造slice

runtime: out of memory: cannot allocate 8002732032-byte block (7995392 in use)
*/
type Solution struct {
	real     []int
	realSize int
}

func Constructor(n int, blacklist []int) Solution {
	blacklistSize := len(blacklist)
	realSize := n - blacklistSize
	if realSize < 0 {
		panic("realSize is valid. lower than zero.")
	}

	// 好像说这里panic了..[[1000000000,[640145908]]
	// 被官方案例hack了
	tmpSlice := make([]int, 0, realSize)
	// tmpSlice := make([]int, realSize)
	// blacklist = sort.IntSlice(blacklist)
	// IntSlice 只是帮 Slice处理好sort需要的方法，实际的sort还需要调用！
	sortT := sort.IntSlice(blacklist)
	sort.Sort(sortT)
	fmt.Println(sortT)
	j := 0
	for i := 0; i < n; i++ {
		if j < blacklistSize && i == sortT[j] {
			j++
			continue
		}
		tmpSlice = append(tmpSlice, i)
	}

	return Solution{real: tmpSlice, realSize: realSize}
}

func (this *Solution) Pick() int {
	i := rand.Intn(this.realSize)
	return this.real[i]
}

/**
 * Your Solution object will be instantiated and called as such:
 * obj := Constructor(n, blacklist);
 * param_1 := obj.Pick();
 */

func main() {
	// n := 7
	// blacklist := []int{2, 3, 5}
	n := 4
	blacklist := []int{2, 1}
	obj := Constructor(n, blacklist)
	for i := 0; i < 2*n; i++ {
		fmt.Println(obj.Pick())
	}
}
