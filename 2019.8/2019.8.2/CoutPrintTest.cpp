#include <cstdio>
#include <iostream>
int main() {
  std::ios::sync_with_stdio(false);
  //关闭同步后，cin/cout 将使用独立缓冲区，而不是将输出同步至 scanf/printf
  //的缓冲区，从而减少 IO 耗时
  std::cout << "a\n";
  // cout 下，使用'\n'换行时，内容会被缓冲而不会被立刻输出，应该使用 endl
  // 来换行并立刻刷新缓冲区
  printf("b\n");
  // printf 的 '\n' 会刷新 printf 的缓冲区，导致输出错位
  std::cout << "c\n";
  return 0;  //程序结束时，cout 的缓冲区才会被输出
}