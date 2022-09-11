package main

import (
	"container/heap"
	"math"
	"sort"
)

/*
mincostToHireWorkers 雇佣k人的最低成本
只想到暴力得枚举k人，然后根据质量比例计算薪水
贪心是希望先找到一个质量最高，然后期望薪资最低的人，然后用继续贪心第二个人
也就是计算质量/期望...但是第一个例子就直接否定了这个思路
看答案吧

总质量值是可以变动的，不同的质量值有不同的最小薪资和，答案还是666
*/
func mincostToHireWorkers(quality, wage []int, k int) float64 {
	n := len(quality)
	h := make([]int, n)
	for i := range h {
		h[i] = i
	}
	// 权重小到大排序
	sort.Slice(h, func(i, j int) bool {
		a, b := h[i], h[j]
		return quality[a]*wage[b] > quality[b]*wage[a]
	})
	totalq := 0
	q := hp{}
	for i := 0; i < k-1; i++ {
		totalq += quality[h[i]]
		heap.Push(&q, quality[h[i]])
	}
	ans := 1e9
	for i := k - 1; i < n; i++ {
		idx := h[i]
		totalq += quality[idx]
		heap.Push(&q, quality[idx])
		ans = math.Min(ans, float64(wage[idx])/float64(quality[idx])*float64(totalq))
		totalq -= heap.Pop(&q).(int)
	}
	return ans
}

type hp struct{ sort.IntSlice }

func (h hp) Less(i, j int) bool  { return h.IntSlice[i] > h.IntSlice[j] }
func (h *hp) Push(v interface{}) { h.IntSlice = append(h.IntSlice, v.(int)) }
func (h *hp) Pop() interface{} {
	a := h.IntSlice
	v := a[len(a)-1]
	h.IntSlice = a[:len(a)-1]
	return v
}
