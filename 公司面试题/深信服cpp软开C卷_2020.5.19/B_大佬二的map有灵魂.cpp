#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <bits/stdc++.h>
using namespace std;

int unescape_c_quoted(char *buf, const char *str)
{
    //TODO:
    string res;
    map<char, char> ch_group = {{'n', '\n'}, {'r', '\r'}, {'t', '\t'}};
    int len = strlen(str);

    if(str[0] != '\"' || str[len - 1] != '\"'){
        strcpy(buf, "error");
        return -1;
    }

    bool flag = false;
    for(int i = 1; i < len - 1; i++){
        if(!flag && str[i] == '\\'){
            flag = true;
        }
        else{
            if(flag && ch_group.count(str[i])){
                res += ch_group[str[i]];
            }
            else{
                res += str[i];
            }

            flag = false;
        }
    }
    strcpy(buf, res.c_str());
    return 0;
}

int main()
{
    char str[10000];
    char buf[10000];
    int len;

    if (fgets(str, sizeof(str), stdin) == NULL) {
        fprintf(stderr, "input error\n");
        return 0;
    }
    len = strlen(str);
    while (len > 0 && isspace(str[len - 1])) {
        str[len - 1] = '\0';
        --len;
    }

    unescape_c_quoted(buf, str);
    printf("%s\n", buf);

    fprintf(stderr, "input:%s\noutput:%s\n", str, buf);
    return 0;
}