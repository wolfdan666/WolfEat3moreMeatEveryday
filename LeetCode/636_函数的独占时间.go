package main

import (
	"fmt"
	"strconv"
	"strings"
)

/*
题解思路:
感觉就是模拟一个stack的调用，然后end用数字加一去操作.
__好久没写了，看题到AC1小时，离大谱，还是要多练.
*/
func exclusiveTime(n int, logs []string) []int {
	stack := make([]int, 0, n)
	ans := make([]int, n)
	splitLog := func(in string) (funcID int, opStr string, index int) {
		res := strings.Split(in, ":")
		if len(res) != 3 {
			panic(res)
		}
		funcID, err := strconv.Atoi(res[0])
		if err != nil {
			panic(err)
		}
		opStr = res[1]
		index, err = strconv.Atoi(res[2])
		if err != nil {
			panic(err)
		}
		return
	}
	preFuncID, preOpStr, preIndex := splitLog(logs[0])
	stack = append(stack, preFuncID)
	if preOpStr != "start" {
		panic("first opStr != start")
	}
	for _, log := range logs[1:] {
		funcID, opStr, index := splitLog(log)
		// fmt.Println(funcID, opStr, index)
		if opStr != "start" {
			if funcID != preFuncID {
				errMsg := fmt.Sprintf("stack funcID %v not match preFuncID %v\n",
					funcID, preFuncID)
				panic(errMsg)
			}
			index++
			ans[funcID] += index - preIndex
			// fmt.Println(funcID, ans[funcID])
			stack = stack[:len(stack)-1]
		} else {
			if preFuncID > -1 {
				ans[preFuncID] += index - preIndex
			}
			// fmt.Println(preFuncID, ans[preFuncID])
			stack = append(stack, funcID)
		}
		if len(stack) > 0 {
			preFuncID, preOpStr, preIndex = stack[len(stack)-1], opStr, index
		} else {
			// WA了一发，因为没处理这里
			preFuncID, preOpStr, preIndex = -1, opStr, index
		}
	}

	return ans
}

/*
题解比我简洁一点，学习
*/
func exclusiveTime_ans(n int, logs []string) []int {
	ans := make([]int, n)
	type pair struct{ idx, timestamp int }
	st := []pair{}
	for _, log := range logs {
		sp := strings.Split(log, ":")
		idx, _ := strconv.Atoi(sp[0])
		timestamp, _ := strconv.Atoi(sp[2])
		if sp[1][0] == 's' {
			if len(st) > 0 {
				ans[st[len(st)-1].idx] += timestamp - st[len(st)-1].timestamp
				st[len(st)-1].timestamp = timestamp
			}
			st = append(st, pair{idx, timestamp})
		} else {
			p := st[len(st)-1]
			st = st[:len(st)-1]
			ans[p.idx] += timestamp - p.timestamp + 1
			if len(st) > 0 {
				st[len(st)-1].timestamp = timestamp + 1
			}
		}
	}
	return ans
}

/*
执行结果：
解答错误
显示详情
添加备注

通过测试用例：
118 / 120
输入：
3
["0:start:0","0:end:0","1:start:1","1:end:1","2:start:2","2:end:2","2:start:3","2:end:3"]
输出：
[2,2,3]
预期结果：
[1,1,2]
*/
func main() {
	// n := 2
	// n := 1
	n := 3
	// logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
	// ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
	// logs := []string{"0:start:0", "1:start:2", "1:end:5", "0:end:6"}
	// logs := []string{"0:start:0", "0:start:2", "0:end:5", "0:start:6", "0:end:6", "0:end:7"}
	logs := []string{"0:start:0", "0:end:0", "1:start:1", "1:end:1", "2:start:2", "2:end:2", "2:start:3", "2:end:3"}
	fmt.Println(exclusiveTime(n, logs))
}
