package main

import "fmt"

/*
直接遍历就完事了
*/

func distanceBetweenBusStops(distance []int, start int, destination int) int {
	ans := 0
	if start == destination {
		return ans
	}
	if start > destination {
		start, destination = destination, start
	}
	tmp := 0
	n := len(distance)
	for i := start; i < destination; i++ {
		tmp += distance[i]
	}
	ans, tmp = tmp, 0
	for i := destination; i < start+n; i++ {
		tmp += distance[i%n]
	}
	if tmp < ans {
		ans = tmp
	}
	return ans
}

// 答案写得比我更简洁，学习之
func distanceBetweenBusStops_ans(distance []int, start, destination int) int {
	if start > destination {
		start, destination = destination, start
	}
	sum1, sum2 := 0, 0
	for i, d := range distance {
		if start <= i && i < destination {
			sum1 += d
		} else {
			sum2 += d
		}
	}
	return min(sum1, sum2)
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func main() {
	distance := []int{1, 2, 3, 4}
	start := 0
	destination := 2
	fmt.Println(distanceBetweenBusStops(distance, start, destination))
}
