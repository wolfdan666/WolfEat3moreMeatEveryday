// 运行此文件记得在同一文件夹下创建test.txt空文件，重复运行时要记得清空
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    if ((fd = open("test.txt", O_RDWR | O_APPEND)) == -1) {
        printf("open failed\n");
        exit(0);
    }

    write(fd, "World!\n", 7);

    int r;
    if ((r = lseek(fd, 0, SEEK_SET)) == -1) {
        printf("lseek failed\n");
        close(fd);
        exit(0);
    }

    write(fd, "Hello", 5);
    close(fd);

    if ((fd = open("test.txt", O_RDWR | O_APPEND)) == -1) {
        printf("open failed\n");
        exit(0);
    }

    if ((r = lseek(fd, 0, SEEK_SET)) == -1) {
        printf("lseek failed\n");
        close(fd);
        exit(0);
    }

    char str[32];
    int test = read(fd, str, 15);
    // test = 12,确实是读到了12个...
    printf("%d\n", test);
    // 下面这个printf当然会在windows出现乱码，因为没有读到'\0',所以乱码
    printf("%s\n", str);

    str[test] = '\0';
    printf("%s\n", str);

    close(fd);

    return 0;
}