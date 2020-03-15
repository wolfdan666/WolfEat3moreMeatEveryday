1. 之后看了堆排序...感觉挺简单的，自己居然忘了...
2. 然后快排忘了换回基准...菜爆了
3. 运行错误了两次之后，那个人说今天先这样吧...然后拜拜了
4. 面试进度竟然没有变灰...可能他先去吃饭了吧

# 待补充知识点
- 协程
* https://www.liaoxuefeng.com/wiki/897692888725344/923057403198272
* https://zh.wikipedia.org/wiki/%E5%8D%8F%E7%A8%8B
- golang中interface
- const
- 虚函数
- http，https，https加密过程
- ARP
- 堆排序
```cpp
/*
父节点i的左子节点在位置(2i+1)
父节点i的右子节点在位置(2i+2)
子节点i的父节点在位置floor((i-1)/2)

---
若以升序排序说明，把数组转换成最大堆积(Max-Heap Heap)，
这是一种满足最大堆积性质(Max-Heap Property)的二叉树：
对于除了根之外的每个节点i, A[parent(i)] ≥ A[i]

重复从最大堆积取出数值最大的结点(把根结点和最后一个结点交换，
把交换后的最后一个结点移出堆)，并让残余的堆积维持最大堆积性质

---
下标的树形...
     0
   1   2
  3 4 5 6

*/

#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int arr[], int start, int end) {
    // 建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;

    // 下面是一个log(n)的树形下探操作

    // 若子节点指标在范围内才做比较
    while (son <= end) {
        // 先比较两个子节点大小，选择最大的
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        // 如果父节点大于子节点代表调整完毕，直接跳出函数
        if (arr[dad] > arr[son])
            return;
        // 否则交换父子内容再继续子节点和孙节点比较
        else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(int arr[], int len) {
    // 这里O(nlog(n))找出最大的
    // 并且保证(建树)对于除了根之外的每个节点i, A[parent(i)] ≥ A[i]

    // 初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);

    // 下面是O(nlog(n))把最大的移动到最后面,然后重新找最大的

    // 先将第一个元素和已经排好的元素前一位做交换，
    // 再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

int main() {
    int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    heap_sort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
    cout << endl;
    return 0;
}
```