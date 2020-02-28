#include "apue.h"

int globvar = 6; /* external variable in initialized data */
char buf[] = "a write to stdout\n";

int main(void) {
    int var; /* automatic variable on the stack */
    pid_t pid;
    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        err_sys("write error");
    printf("before fork\n"); /* we don’t flush stdout */

    /* 这里fork()之后应该是有两个线程从这里开始继续执行,所以才会一个if_else if感觉执行了2次的感觉
        神奇的多线程
    */

    if ((pid = fork()) < 0) {
        err_sys("fork error");
    } else if (pid == 0) { /* child */
        globvar++;         /* modify variables */
        var++;
    } else {
        sleep(2); /* parent */
    }
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    exit(0);
}

/*
a write to stdout
before fork
pid = 13279, glob = 7, var = 89
pid = 13278, glob = 6, var = 88

Press ENTER or type command to continue...
*/