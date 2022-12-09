// g++ A.cpp -o A.o -g --std=c++11 -pthread
// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;

// #include <pthread.h>
// #include <string.h>
// #include <syscall.h>
// #include <unistd.h>

// #include <iostream>

// using namespace std;

// pthread_mutex_t test_mutex = PTHREAD_MUTEX_INITIALIZER;
// pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// void *foo(void *pBuffer) {
//     pthread_mutex_lock(&test_mutex);
//     strcpy((char *)pBuffer, "hello");  //主线程的栈数据在此被修改
//     pthread_mutex_unlock(&test_mutex);
//     pthread_cond_signal(&cond);
// }

// int main(int n, char *arg[]) {
//     char Buffer[20];  //主线程的栈数据
//     pthread_t pthread_id1;
//     pthread_create(&pthread_id1, NULL, foo, (void *)Buffer);
//     pthread_mutex_lock(&test_mutex);
//     pthread_cond_wait(&cond, &test_mutex);
//     //注意pthread_cond_wait()的使用方法 pthread_mutex_unlock(&test_mutex);
//     cout << Buffer << endl;  // 输出数据Buffer到标准输出
//     return 0;
// }

#include <pthread.h>
#include <string.h>
#include <syscall.h>
#include <unistd.h>

#include <iostream>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *foo(void *pBuffer) {
    pthread_mutex_lock(&mutex);
    strcpy((char *)pBuffer, "hello");  //主线程的堆数据在此被修改
    pthread_mutex_unlock(&mutex);
    pthread_cond_signal(&cond);
}

int main(int n, char *arg[]) {
    char *Buffer = new char[20];  //主线程的堆数据
    pthread_t pthread_id1;
    pthread_create(&pthread_id1, NULL, foo, (void *)Buffer);
    pthread_mutex_lock(&mutex);
    pthread_cond_wait(&cond, &mutex);  //注意pthread_cond_wait()的使用方法
    pthread_mutex_unlock(&mutex);
    cout << Buffer << endl;  // 输出数据Buffer到标准输出
    return 0;
}
