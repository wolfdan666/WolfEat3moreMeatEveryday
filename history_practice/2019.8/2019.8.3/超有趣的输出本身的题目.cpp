#include <stdio.h>
char *s = "#include<stdio.h>%cchar%c*s=%c%s%c%c%cint main(){printf(s,10,32,34,s,34,59,10);}";
int main() { printf(s, 10, 32, 34, s, 34, 59, 10); }