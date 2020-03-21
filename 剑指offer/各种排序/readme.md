# 各种排序
这个文件中各种排序学习于 2019年12月17日下午
借鉴于 : [手撕九大经典排序算法，看我就够了！](https://zhuanlan.zhihu.com/p/52884590)

桶排序看的wiki百科

快速排序看的 剑指offer

后面关于计数,基数,桶排序又去看了自己买的<算法导论>

2019年12月17日19:51:13 今天花了大概4个半小时,对于排序算法总算有了更深一点的了解了

2019年12月29日11:13:20
补充了单链表的选择排序，更加深入地理解了选择排序为什么对链表稳定，对数组不稳定了,其实具体根据自己的排序的底层算法实现有关系，之前在y算科技面试实习生,面试官和我说只要有一个case是不稳定的，那就认为它是不稳定的(当时说的快排,然后选择排序说不稳定的时候自己犹豫了半天，现在才更深刻地理解)
[单链表选择排序](https://github.com/wolfdan666/WolfEat3moreMeatEveryday/blob/master/%E5%89%91%E6%8C%87offer/%E5%90%84%E7%A7%8D%E6%8E%92%E5%BA%8F/%E5%8D%95%E9%93%BE%E8%A1%A8%E9%80%89%E6%8B%A9%E6%8E%92%E5%BA%8F.cpp)

# 稳定
## 定义
排序前后两个相等的数相对位置不变，则算法稳定。

## 稳定的意义
从一个键上排序，然后再从另一个键上排序，第一个键排序的结果可以为第二个键排序所用。


# 选择排序和插入排序
## 选择排序
是 `i = 0`开始从所有值中选择最小的,一直选到`i = n-1`
```cpp
template<typename T> //整数或浮点数皆可使用，若要使用物件（class）时必须设定大于（>）的运算子功能
void selection_sort(std::vector<T>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < arr.size(); j++)
            if (arr[j] < arr[min])
                min = j;
        std::swap(arr[i], arr[min]);
    }
}
```

## 插入排序
是从左边到右边一个个放到左边已经遍历过的block块中，新进来的根据比较来移动位置
```cpp
void insertion_sort(int arr[], int length){
    int i,j;
    // 从无序区选择数据插入到前面的有序区
    for (i = 1; i < length; i++) {
        int tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp; j--){
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}
```