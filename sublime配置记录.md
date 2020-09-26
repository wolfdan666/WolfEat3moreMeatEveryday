## 2020年09月26日12:12:04 觉得有必有记录一下
1. 安装package control
2. 安装package control里面的插件(科学)
   1. SpaceGray主题
   2. SidebarEnhancements
   3. ChineseLocalization
   4. Terminal
   5. A File icon
   6. ConvertToUTF8
3. 配置C++编译系统
mycpp.sublime-build
```
{
    "cmd": ["g++", "-std=c++11", "${file}", "-o", "${file_path}/${file_base_name}.out"],
    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
    "working_dir": "${file_path}",
    "selector": "source.c, source.c++",

    "variants":
    [
        {
            "name": "Run",
            "cmd": ["bash", "-c", "g++ -std=c++11 '${file}' -o '${file_path}/${file_base_name}.out' && open -a Terminal.app '${file_path}/${file_base_name}.out'"]
        }
    ]
}
```
4. 配置C++snippet
acm.sublime-snippet
```
<snippet>
	<content>
	<![CDATA[
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int inf = 0x3f3f3f3f;
#define LOCAL



int main(int argc, char * argv[])
{
	#ifdef LOCAL
	freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.in", "r", stdin);
	//freopen("/Users/huangjiaming/Documents/Algorithm/oj/data.out", "w", stdout);
	#endif

	${1:/* code */}

	while (~scanf("%d", ${2:/* var */}))
	{

	}

    return 0;
}]]>
	</content>
	<!-- Optional: Set a tabTrigger to define how to trigger the snippet -->
	<tabTrigger>acm</tabTrigger>
	<!-- Optional: Set a scope to limit where the snippet will trigger -->
	<scope>source.c++</scope>
</snippet>
```
