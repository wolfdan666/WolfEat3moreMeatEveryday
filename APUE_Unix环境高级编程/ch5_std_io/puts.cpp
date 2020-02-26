#include <stdio.h>

int main(int argc, char const *argv[])
{
    char * s = "Hello world!";
    // puts自带换行,输出到stdout
    puts(s);

    // fputs不自带换行
    fputs(s,stdout);
    printf("%s", s);
    return 0;
}