/*
2020年02月24日17:06:53 借鉴自:https://github.com/MeiK2333/apue/blob/master/Chapter-04/p6.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./a.out file1 file2\n");
        exit(1);
    }

    char buff[BUF_SIZE];
    int fd1, fd2;
    if ((fd1 = open(argv[1], O_RDWR)) == -1) {
        printf("open %s failure\n", argv[1]);
        exit(1);
    }
    if ((fd2 = open(argv[2], O_RDWR | O_CREAT, 0666)) == -1) {
        printf("open %s failure\n", argv[2]);
        exit(1);
    }

    int cnt, i, all_cnt = 0;
    int f, l;
    while ((cnt = read(fd1, buff, BUF_SIZE))) {
        f = l = 0;

        // 中途有空洞
        // 这里没有处理万一没有空洞的情况......所以一直fd2 write failure
        // 所以追加一个判断

        for(int i = 0; i < cnt; i++){
            if(buff[i] == 0) f = 1;
        }

        if(f) for (i = 0; i < cnt; i++) {
            if (f != 0 && buff[i] == 0) {  // 如果在非空洞状态遇到空洞，则将之前的非空洞序列复制
                if (write(fd2, buff + l, i - l) == -1) {
                    printf("fd2 write failure\n");
                    exit(1);
                }
                f = 0;
            } else if (f == 0 && buff[i] != 0) {  // 如果在空洞状态遇到非空洞，则记录下来位置， lseek 调整位置
                l = i;
                f = 1;
                if (lseek(fd2, all_cnt + i, SEEK_SET) == -1) {
                    printf("lseek failure\n");
                    exit(1);
                }
            }
        }

        // 中途无空洞,或者处理完了空洞
        if (l != cnt) {  // 将没有复制过去的所有都复制过去
            if (write(fd2, buff + l, cnt - l)) {
                printf("fd2 write failure\n");
                exit(1);
            }
        }
        all_cnt += cnt;
    }

    return 0;
}