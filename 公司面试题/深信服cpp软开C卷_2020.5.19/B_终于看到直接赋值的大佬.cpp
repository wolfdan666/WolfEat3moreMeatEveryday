#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>


int unescape_c_quoted(char *buf, const char *str, int len)
{
    //TODO:
    if(*str == NULL || *str != '\"' || str[len-1] != '\"')
        return -1;

    int i=1, j=0;
    for( ; i < len-1; i++){
        if(str[i] != '\\'){
            buf[j] = str[i];
            j++;
        }
        else{
           if(str[i+1] == '\"' || str[i+1] == '\'' || str[i+1] == '\\' || str[i+1] == '\?'){
               buf[j] = str[i+1];
               i++;
               j++;
           }
            else if(str[i+1] == 'n'){
               buf[j] = '\n';
               i++;
               j++;
            }
            else if(str[i+1] == 'r'){
               buf[j] = '\r';
               i++;
               j++;
            }
            else if(str[i+1] == 't'){
               buf[j] = '\t';
               i++;
               j++;
            }
            else if(str[i+1] == '0'){
                buf[j] = '\0';
                i++;
                j++;
            }
            else if(str[i+1] == 'b'){ //删除一个字符
                j--;
                i++;
            }
            else
                return -1;
        }
    }
    return 0;
}

int main()
{
    char str[10000];
    char buf[10000];
    int len;
    int ret;

    if (fgets(str, sizeof(str), stdin) == NULL) {
        fprintf(stderr, "input error\n");
        return 0;
    }
    len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        str[len - 1] = '\0';
        --len;
    }

    ret = unescape_c_quoted(buf, str, len);
    if(ret < 0)
        printf("error\n");
    else
        printf("%s\n", buf);

    fprintf(stderr, "input:%s\noutput:%s\n", str, buf);
    return 0;
}