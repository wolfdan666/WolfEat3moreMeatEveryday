/*
我记得自己曾经看过，结果忘了，GG

面试官认为这应该算是acm的小儿科的

尴尬，他说我计算机基础还不是很扎实，然后说acm给他高预期，但我没有达到预期
*/


//杨氏矩阵查找

//定位法(完整代码)
// #include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;

#define ROW 4
#define COL 4

bool YoungMatrix(int a[][COL], int Value)
{
    int i = 0, j = COL-1;
    while (i < ROW && j >= 0)
    {
        if (a[i][j] > Value)//比要找的数大,就往左走
        {
            j--;
        }
        else if (a[i][j] < Value)//比要找的数小,就往右走
        {
            i++;
        }
        else
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int array[ROW][COL] = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 7, 10, 13 }, { 6, 8, 11, 15 } };
    int KeyValue = 10;

    bool TF = YoungMatrix(array, KeyValue);

    if (TF == true)
    {
        cout << "TRUE,该值存在！" << endl;
    }
    else
    {
        cout << "FALSE,该值不存在！" << endl;
    }

    return 0;
}