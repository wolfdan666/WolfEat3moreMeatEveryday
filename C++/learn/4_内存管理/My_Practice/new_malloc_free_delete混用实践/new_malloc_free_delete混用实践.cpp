/*
 *1》当申请的空间是内置类型时，delete和free可以混用
 *2》当申请的空间是自定义类型时，
 *       1>若没有析构函数，delete和malloc可以混用，有[]和没有[]都相同
 *                  
 * 2>若申请的空间有析构函数时，malloc申请的空间可以用delete和free释放，但是用delete释放时不能加[]
 *                  
 * 3>若申请的空间有析构函数时，new申请的空间不能用free释放，可以用delete释放，但是释放时必须加上[]
 */      
#if 0
int main()
{
    int a = 10;
    int b = 20;
    int *p = (int *)malloc(sizeof(int) * 10);
    int *p1 = new int[10];

    free(p);
    // free(p1);
    // delete p;
    delete p1;

    return 0;
}
#endif

#if 1

class Test {
   private:
    int ma;

   public:
    Test(int x = 0) : ma(x) {}
    ~Test() {}
    void fun() { cout << "Test::fun" << endl; }
};

int main() {
    Test *p1 = (Test *)malloc(sizeof(Test) * 10);
    Test *p2 = new Test[10];

    // free(p1);
    // free(p2);
    // delete p1;
    // delete ((int *)p1-1);
    delete ((int *)p2 - 1);
    // delete []p2;

    return 0;
}
#endif
/*
———————————————— 版权声明：本文为CSDN博主「唯pc远方」的原创文章，遵循CC 4.0 BY -
    SA版权协议，转载请附上原文出处链接及本声明。 原文链接：https
    :  // blog.csdn.net/u014774781/article/details/47836069
    */