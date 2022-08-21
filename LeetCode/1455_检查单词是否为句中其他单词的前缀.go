package main

import (
	"fmt"
	"strings"
)

/*
isPrefixOfWord 字符串对比:检查单词是否为句中其他单词的前缀.
返回第一个句中单词的下标(1开始).无则返回-1.


wa一发:
panic: runtime error: index out of range [3] with length 3
最后执行的输入：
"hello from the other side"
"they"

反思: 没有思考简单问题的特殊用例，还是应该先思考所用的用例之后再开发，也就是先写好单测！！！
*/
func isPrefixOfWord(sentence string, searchWord string) int {
	ans := -1
	words := strings.Split(sentence, " ")
	for index, word := range words {
		isPrefix := true
		for i := range searchWord {
			if len(word) < len(searchWord) {
				isPrefix = false
				break
			}
			if searchWord[i] != word[i] {
				isPrefix = false
				break
			}
		}
		if isPrefix {
			ans = index + 1
			return ans
		}
	}
	return ans
}

/*
答案用的双指针，可以的.
*/
func isPrefixOfWord_ans(sentence, searchWord string) int {
	for i, index, n := 0, 1, len(sentence); i < n; i++ {
		start := i
		for i < n && sentence[i] != ' ' {
			i++
		}
		end := i
		if strings.HasPrefix(sentence[start:end], searchWord) {
			return index
		}
		index++
	}
	return -1
}

func main() {
	sentence := "i love eating burger"
	// searchWord := "burg"
	searchWord := "burgs"
	fmt.Println(isPrefixOfWord(sentence, searchWord))
}
