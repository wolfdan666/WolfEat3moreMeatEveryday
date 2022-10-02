package main

import "fmt"

/*
canTransform start是否能转化为end.
其实就是去除掉其中所有的X，然后看所有的L，R字符是否是相同的循序即可.
可以直接使用双指针对比即可. O(n).

执行结果：
解答错误
通过测试用例：
59 / 94
输入：
"LXXLXRLXXL"
"XLLXRXLXLX"
输出：
true
预期结果：
false

2022年10月02日16:00:19 发现看错题意了...
2022年10月02日16:42:21 发先这里更加理解反了...
~~只有LX转XL，不能XL转LX~~
~~只有XR转RX，不能RX转XR~~

2022年10月02日16:32:33 调整了一发竟然还是WA，震惊
执行结果：
解答错误
通过测试用例：
82 / 94
输入：
"LXXLXRLXXL"
"XLLXRXLXLX"
输出：
true
预期结果：
false

2022年10月02日16:34:57 只能start转变成end，不能end也来进行变动...

2022年10月02日16:39:50 又WA，我无语了，这么多坑吗？
通过测试用例：
55 / 94
输入：
"RXXLRXRXL"
"XRLXXRRLX"
输出：
false
预期结果：
true

....**一次移动操作指用一个"LX"替换一个"XL"，或者用一个"XR"替换一个"RX"。**
替换，前面理解错了

2022年10月02日16:50:16 麻了...
通过测试用例：
70 / 94
输入：
"XXXLXXXXXX"
"XXXLXXXXXX"
输出：
false
预期结果：
true

2022年10月02日16:53:22 AC，中途理解错题意WA了4次，丢人
总结:
第一次想得太简单，第二次又想得太复杂...两次理解错了题意，没有在题意上下功夫(只要琢磨5分钟)，导致浪费了10倍的时间-50分钟.
这是以前打比赛和做系统设计的教训啊，怎么现在又犯了...要谨记...

2022年10月02日16:56:40 看答案发现判断完左右位置之后，不用判断是否被堵住...因为这个被堵住会在下一次进行判断
*/
func canTransform(start string, end string) bool {
	sLen := len(start)
	eLen := len(end)
	if sLen != eLen {
		panic("start len is not equal end len.")
	}

	i := 0
	j := 0
	for i < sLen && j < eLen {
		// 都各自找到第一个不可变动值.
		for i < sLen && start[i] == 'X' {
			i++
		}
		for j < eLen && end[j] == 'X' {
			j++
		}
		// 这里还是要判断一下i,j是否越界.
		if i == sLen || j == eLen {
			break
		}
		// 如果对照结果不相等，直接返回false. 否则继续找一个值对照.
		if start[i] != end[j] {
			return false
		} else {
			if start[i] == 'R' {
				// R只能右移, 如果要左移会失败.
				// tmpi, tmpj := i, j
				if i > j {
					// 只能start转变成end，不能end也来进行变动...
					return false
					// tmpi, tmpj = j, i
				}

				// 2022年10月02日16:56:40 看答案发现判断完左右位置之后，不用判断是否被堵住...因为这个被堵住会在下一次进行判断
				/* k := tmpi + 1
				// RRRXXX 和 XXXRRR 其实也可以的（这种可能需要O((n/2)^2),在数据范围内，可以的）.
				// 需要hack掉这种情况，所以只要判断有没有'L'.
				for k <= tmpj && start[k] != 'L' {
					k++
				}
				// 被L堵住，则返回false.这里要注意+1.
				if k != tmpj+1 {
					fmt.Printf("debug R: i:%v, j:%v, k:%v\n", i, j, k)
					return false
				} */
			} else {
				// L只能左移，如果要右移会失败.
				// tmpi, tmpj := i, j
				// 这里等于也合法...第4WA，麻了
				if i >= j {
					// tmpi, tmpj = j, i
				} else {
					// 只能start转变成end，不能end也来进行变动...
					return false
				}

				// 2022年10月02日16:56:40 看答案发现判断完左右位置之后，不用判断是否被堵住...因为这个被堵住会在下一次进行判断
				// k := tmpj - 1
				// for k >= tmpi && start[k] != 'R' {
				// 	k--
				// }
				// if k != tmpi-1 {
				// 	fmt.Printf("debug L: i:%v, j:%v, k:%v\n", i, j, k)
				// 	return false
				// }
			}
			i++
			j++
		}
	}
	// 这时候一定只有一个管道有剩余，看是否有残留值.
	for i < sLen && start[i] == 'X' {
		i++
	}
	for j < eLen && end[j] == 'X' {
		j++
	}
	if i == sLen && j == eLen {
		return true
	}
	fmt.Printf("debug: i:%v, j:%v\n", i, j)
	return false
}

/*
canTransformAns 题解简洁版.
*/
func canTransformAns(start, end string) bool {
	i, j, n := 0, 0, len(start)
	for i < n && j < n {
		for i < n && start[i] == 'X' {
			i++
		}
		for j < n && end[j] == 'X' {
			j++
		}
		if i < n && j < n {
			if start[i] != end[j] {
				return false
			}
			c := start[i]
			if c == 'L' && i < j || c == 'R' && i > j {
				return false
			}
			i++
			j++
		}
	}
	for i < n {
		if start[i] != 'X' {
			return false
		}
		i++
	}
	for j < n {
		if end[j] != 'X' {
			return false
		}
		j++
	}
	return true
}

func main() {
	// s := "LXXLXRLXXL"
	// e := "XLLXRXLXLX"
	// e := "XXXLLL"
	// s := "LLLXXX"
	s := "XXXLXXXXXX"
	e := "XXXLXXXXXX"
	// s := "LXXLXRLXXL"
	// e := "XLLXRXLXLX"
	// s := "RXXLRXRXL"
	// e := "XRLXXRRLX"
	fmt.Println(canTransform(s, e))
}
