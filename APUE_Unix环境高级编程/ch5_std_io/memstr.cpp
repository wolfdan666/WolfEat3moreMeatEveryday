// 2020年02月26日22:31:54   52行处还是不懂,卡了40分钟,自闭
#include "apue.h"

#define BSZ 48

int
main()
{
    FILE *fp;
    char buf[BSZ];
    char data[62];

    memset(buf, 'a', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    // 通过写入申请内存流,那么就一开始截断文件(这里是buf)从0开始
    if ((fp = fmemopen(buf, BSZ, "w+")) == NULL)
        err_sys("fmemopen failed");
    printf("initial buffer contents: %s\n", buf);
    fprintf(fp, "hello, world");
    printf("before flush: %s\n", buf);
    fflush(fp);
    printf("after fflush: %s\n", buf);
    // 这里导致偏移量到了12
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    memset(buf, 'b', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';

    printf("initial buffer contents: %s\n", buf);

    fprintf(fp, "hello, world");

    printf("hello world buffer contents: %s\n", buf);

    fgets ( data, 60, fp );
    printf("SEEK_POS Display- %s\n", data);

    // fseek让缓冲区刷新,然后就是从12的位置向后添加hello, world\0,然后再fseek到文件开始部分
    // To set file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET); // We can use rewind(fp); also

    fseek(fp, 0, SEEK_SET);
    printf("after  fseek: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    memset(buf, 'c', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    fprintf(fp, "hello, world");
    // fclose刷新流,然后就是在文件开始部分写入hello, world,但是竟然没有null截断??????
    fclose(fp);
    printf("after fclose: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    return(0);
}
