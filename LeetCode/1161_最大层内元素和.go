package main

import "math"

/**
 * Definition for a binary tree node.
 */
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 感觉这个题目和之前的一次面试题很像，就是bfs，但是面试时紧张记录了太多上下层的状态
func maxLevelSum(root *TreeNode) int {
	if root == nil {
		return 0
	}
	maxSum := math.MinInt64
	level := 1
	levelNodeCnt := 1
	queue := make([]*TreeNode, 0, 10)
	queue = append(queue, root)
	queueCnt := 1
	levelSum := 0
	ans := 1
	for queueCnt != 0 {
		head := queue[0]
		queue = queue[1:]
		queueCnt--
		levelNodeCnt--
		levelSum += head.Val
		if head.Left != nil {
			queue = append(queue, head.Left)
			queueCnt++
		}
		if head.Right != nil {
			queue = append(queue, head.Right)
			queueCnt++
		}
		if levelNodeCnt == 0 {
			if levelSum > maxSum {
				maxSum, ans = levelSum, level
			}
			level++
			// 这种没考虑null没有加入
			// levelNodeCnt = int(math.Pow(2, float64(level-1)))
			levelNodeCnt = len(queue)
			levelSum = 0
		}
	}

	return ans
}

// 答案比我的简洁多了
// bfs
func maxLevelSum_ans_Bfs(root *TreeNode) int {
	ans, maxSum := 1, root.Val
	q := []*TreeNode{root}
	for level := 1; len(q) > 0; level++ {
		tmp := q
		q = nil
		sum := 0
		for _, node := range tmp {
			sum += node.Val
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}
		if sum > maxSum {
			ans, maxSum = level, sum
		}
	}
	return ans
}

/*
作者：LeetCode-Solution
链接：https://leetcode.cn/problems/maximum-level-sum-of-a-binary-tree/solution/zui-da-ceng-nei-yuan-su-he-by-leetcode-s-2tm4/
*/
// dfs
func maxLevelSum_ans_Dfs(root *TreeNode) (ans int) {
	sum := []int{}
	var dfs func(*TreeNode, int)
	dfs = func(node *TreeNode, level int) {
		if level == len(sum) {
			sum = append(sum, node.Val)
		} else {
			sum[level] += node.Val
		}
		if node.Left != nil {
			dfs(node.Left, level+1)
		}
		if node.Right != nil {
			dfs(node.Right, level+1)
		}
	}
	dfs(root, 0)
	for i, s := range sum {
		if s > sum[ans] {
			ans = i
		}
	}
	return ans + 1 // 层号从 1 开始
}
