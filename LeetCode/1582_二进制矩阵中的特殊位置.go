package main

import "fmt"

// numSpecial 找出矩阵中十字里唯一是1的个数
func numSpecial(mat [][]int) int {
	check := func(mat [][]int, x int, y int) bool {
		xlen := len(mat)
		ylen := len(mat[0])
		// 先对x行的y个值进行检测
		for j := 0; j < ylen; j++ {
			if j == y {
				continue
			}
			if mat[x][j] == 1 {
				return false
			}
		}

		// 再对y列的x个值进行检测
		for i := 0; i < xlen; i++ {
			if i == x {
				continue
			}
			if mat[i][y] == 1 {
				return false
			}
		}
		return true
	}

	xlen := len(mat)
	if xlen == 0 {
		panic("wrong input")
	}
	ylen := len(mat[0])
	if ylen == 0 {
		panic("wrong input")
	}
	ans := 0
	for i, row := range mat {
		for j, v := range row {
			if v == 1 {
				if check(mat, i, j) {
					ans++
				}
			}
		}
	}
	return ans
}

/*
numSpecialAns 预处理行列的方式比我的暴力方法快，还有一种是压缩到第一行的，
理解起来比较复杂，不易读，自己理解一遍就行，不贴出来了
*/
func numSpecialAns(mat [][]int) (ans int) {
	rowsSum := make([]int, len(mat))
	colsSum := make([]int, len(mat[0]))
	for i, row := range mat {
		for j, x := range row {
			rowsSum[i] += x
			colsSum[j] += x
		}
	}
	for i, row := range mat {
		for j, x := range row {
			if x == 1 && rowsSum[i] == 1 && colsSum[j] == 1 {
				ans++
			}
		}
	}
	return
}

func main() {
	mat := [][]int{{0, 0, 0, 1},
		{1, 0, 0, 0},
		{0, 1, 1, 0},
		{0, 0, 0, 0}}
	fmt.Println(numSpecial(mat))
}
