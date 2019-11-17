// 感谢https://github.com/MeiK2333/apue/tree/master/Chapter-03  提供的参考答案，让我能够对文件操作的知识了解更深入

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

struct Node {
    int fd;
    struct Node *next;
};

void free_fd(struct Node *head) {
    struct Node *cur;
    while (head->next != NULL) {
        close(head->next->fd);
        printf("close fd %d\n", head->next->fd);
        cur = head->next;
        free(head);
        head = cur;
    }
}

int my_dup2(int fd, int fd2) {
    if (fd == fd2) {
        return fd;
    }

    close(fd2);

    struct Node *head = (struct Node *) malloc(sizeof(struct Node));
    struct Node *cur = head;
    int fd_temp;
    while ((fd_temp = dup(fd)) != fd2) {
        printf("create fd %d\n", fd_temp);
        if (fd_temp == -1) {
            free_fd(head);
            return -1;
        }
        struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
        temp->fd = fd_temp;
        temp->next = NULL;
        cur->next = temp;
        cur = cur->next;
    }

    free_fd(head);
    return fd2;
}

int main() {
    // my_dup2创建到文件描述符15,STDOUT_FILENO是1,但是0,1,2(对应着STDIN_FILENO,STDOUT_FILENO,STDERR_FILENO)都在shell已经打开
    // 所以每次dup都获取当前最小可用的文件描述符，然后通过尾插法插入链表，最后使用free删除
    int fd = my_dup2(STDOUT_FILENO, 15);
    // 给文件描述符15号 写入 "Hello World!\0"的 13个字符
    write(15, "Hello World!\n", 13);
    return 0;
}