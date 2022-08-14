package main

import (
	"fmt"
	"strings"
)

/*
maxScore 分割字符串，返回左边0，右边1的最大得分.
思路: 直接遍历，dp计算左边0的个数，然后第二次遍历，直接获取左边0，右边1的个数最大值

WA 1:
通过测试用例：
96 / 104
输入：
"00"
输出：
2
预期结果：
1
*/
func maxScore(s string) int {
	sz := len(s)
	zeroArr := make([]int, sz)
	var ans int
	for i, c := range s {
		if c == '0' {
			if i == 0 {
				zeroArr[i]++
				continue
			}
			zeroArr[i] = zeroArr[i-1] + 1
		} else {
			if i == 0 {
				continue
			}
			zeroArr[i] = zeroArr[i-1]
		}
	}
	// fmt.Printf("zeroArr: %v\n", zeroArr)
	for i := range s {
		// WA 1
		if i == sz-1 {
			break
		}
		// fmt.Printf("right: %v\n", (sz - (i + 1) - (zeroArr[sz-1] - zeroArr[i])))
		tmpAns := zeroArr[i] + (sz - (i + 1) - (zeroArr[sz-1] - zeroArr[i]))
		if tmpAns > ans {
			ans = tmpAns
		}
	}

	return ans
}

// 答案没用累计和，用的左右移动过程中，分数值变动的方式
func maxScoreAns(s string) int {
	score := int('1'-s[0]) + strings.Count(s[1:], "1")
	ans := score
	for _, c := range s[1 : len(s)-1] {
		if c == '0' {
			score++
		} else {
			score--
		}
		ans = max(ans, score)
	}
	return ans
}

func max(a, b int) int {
	if b > a {
		return b
	}
	return a
}

func main() {
	s := "011101"
	fmt.Println(maxScore(s))
	s = "00111"
	fmt.Println(maxScore(s))
	s = "1111"
	fmt.Println(maxScore(s))
	s = "00"
	fmt.Println(maxScore(s))
}
