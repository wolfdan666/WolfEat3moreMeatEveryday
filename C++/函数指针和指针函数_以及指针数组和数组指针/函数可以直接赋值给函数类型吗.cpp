#include <assert.h>
#include <stdio.h>

// 求最小值
double GetMin(double *dbData, int iSize) {
    double dbMin;
    int i;
    assert(iSize > 0);
    dbMin = dbData[0];

    for (i = 1; i < iSize; i++) {
        if (dbMin > dbData[i]) {
            dbMin = dbData[i];
        }
    }

    return dbMin;
}

// 求最大值
double GetMax(double *dbData, int iSize) {
    double dbMax;
    int i;
    assert(iSize > 0);
    dbMax = dbData[0];

    for (i = 1; i < iSize; i++) {
        if (dbMax < dbData[i]) {
            dbMax = dbData[i];
        }
    }

    return dbMax;
}

// 求平均值
double GetAverage(double *dbData, int iSize) {
    double dbSum = 0;
    int i;
    assert(iSize > 0);
    for (i = 0; i < iSize; i++) dbSum += dbData[i];

    return dbSum / iSize;
}

// 未知算法
double UnKnown(double *dbData, int iSize) { return 0; }

// 定义函数类型
typedef double (PF)(double *dbData, int iSize);

// 根据字符得到操作类型，返回函数
// error: 'GetOperation' declared as function returning a function
// PF GetOperation(char c) {
//     switch (c) {
//         case 'M':
//             return *GetMax;
//         case 'm':
//             return *GetMin;
//         case 'a':
//             return *GetAverage;
//         default:
//             return *UnKnown;
//     }
// }

int main(void) {
    // error: function 'double getmin(double*, int)' is initialized like a variable
    // PF getmin = *GetMin;
    double dbData[] = {3.1415926, 1.4142, -0.5, 999, -313, 365};
    int iSize = sizeof(dbData) / sizeof(dbData[0]);
    char c;
    printf("Please input the Operation :\n");
    c = getchar();
    // 通过函数指针调用函数
    // printf("result is % lf\n", GetOperation(c)(dbData, iSize));
}
