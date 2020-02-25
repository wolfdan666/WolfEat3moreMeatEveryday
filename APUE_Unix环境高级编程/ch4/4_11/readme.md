# 4-11题的测试
花了大概5-6个小时,延伸解决了各种问题,终于测试完了这个题目,然后结果如下

```bash
wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ●  ll
总用量 64K
-rw-r--r-- 1 wolfdan wolfdan 4.7K 2月  22 14:56 ftw8.c
-rw-r--r-- 1 wolfdan wolfdan 5.3K 2月  25 16:09 ftw8_test.c
-rwxr-xr-x 1 wolfdan wolfdan  19K 2月  25 16:15 ftw8_test.out
-rw-r--r-- 1 wolfdan wolfdan 4.9K 2月  25 16:12 other_ftw8.c
-rwxr-xr-x 1 wolfdan wolfdan  19K 2月  25 16:15 other_ftw8.out
 wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ●  ./ftw8_test.out ../..
fullpath return have come...
fullpath return have come...
fullpath return have come...
fullpath return have come...
fullpath return have come...
regular files  =      20, 80.00 %
directories    =       5, 20.00 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =       0,  0.00 %
sockets        =       0,  0.00 %
time: 236 us
 wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ●  ./other_ftw8.out ../..
come here,chdir ..
come here,chdir ..
come here,chdir ..
come here,chdir ..
come here,chdir ..
regular files  =      20, 80.00 %
directories    =       5, 20.00 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =       0,  0.00 %
sockets        =       0,  0.00 %
time: 214 us
 wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ●  ./ftw8_test.out ..
fullpath return have come...
fullpath return have come...
fullpath return have come...
regular files  =      14, 82.35 %
directories    =       3, 17.65 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =       0,  0.00 %
sockets        =       0,  0.00 %
time: 128 us
 wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ●  ./other_ftw8.out ..
come here,chdir ..
come here,chdir ..
come here,chdir ..
regular files  =      14, 82.35 %
directories    =       3, 17.65 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =       0,  0.00 %
sockets        =       0,  0.00 %
time: 142 us
 wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ●  ./ftw8_test.out .
fullpath return have come...
regular files  =       5, 83.33 %
directories    =       1, 16.67 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =       0,  0.00 %
sockets        =       0,  0.00 %
time: 103 us
 wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ●  ./other_ftw8.out .
come here,chdir ..
regular files  =       5, 83.33 %
directories    =       1, 16.67 %
block special  =       0,  0.00 %
char special   =       0,  0.00 %
FIFOs          =       0,  0.00 %
symbolic links =       0,  0.00 %
sockets        =       0,  0.00 %
time: 103 us
 wolfdan@wolfdan-PC  ~/Desktop/WolfdanEat3moreMeatEveryday/Unix环境高级编程/ch4/4_11   master ● 

```

总结就是不相上下

主要感觉是这个递归函数完全没有必要回溯啊,每次都是从根遍历到所有的叶子,所以根本没有必要chdir(..)都不会错

不懂作者要表达什么,可能是让我更深入理解这个ftw8.c程序吧,也可能是我的理解有偏差吧