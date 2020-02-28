// 2020年02月26日22:31:54   52行处还是不懂,卡了40分钟,自闭
// 2020年02月27日18:06:23  自闭4个多小时终于理解了,因为5.7的那个源码题
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
    // 通过w+读写申请内存流,那么就一开始截断文件(这里是buf)从0开始
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

    // fseek让缓冲区刷新,然后就是从12的位置向后添加hello, world\0,然后再fseek到文件开始部分
    // To set file pointer to the beginning of the file
    fseek(fp, 0, SEEK_SET); // We can use rewind(fp); also

    printf("after  fseek: %s\n", buf);
    printf("buffer[26] is still b: %c\n", buf[26]);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    // 可以通过这样读取出,虽然seek的当前位置变成了开头的地方,但是数量量其实还是有24个Bytes
    fgets ( data, 60, fp );
    printf("\nwhen SEEK_POS = 0.fmemopen data is %s\n And fmemopen still has %d bytes\n\n", data,strlen(data));

    // 我的读取操作完还变动seek位置,所以我们操作完再搞回去
    fseek(fp, 0, SEEK_SET);

    memset(buf, 'c', BSZ-2);
    buf[BSZ-2] = '\0';
    buf[BSZ-1] = 'X';
    fprintf(fp, "hello, world");
    // fclose刷新流,然后就是在文件开始部分写入hello, world,但是竟然没有null截断??????

    /*
    Third, a null byte is written at the current position in the stream whenever we
    increase the amount of data in the stream’s buffer <font color=red>**and**</font> call fclose,
     fflush, fseek,fseeko, or fsetpos

　　 中间是<font color=red>**and**</font> 所以要同时满足这两个条件才会增加一个null字节。
    <font color=red>**因为最后我们的内存流中其实是还有24个字节的,只是把当前位置移动到了开头的位置,
    所以其实不满足前面的数据量增加**</font> ,所以最后一段代码并不会增加一个null字节。
    */
    fclose(fp);
    printf("after fclose: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    return(0);
}
