# 起因
因为自己觉得自己一直按照日期写自己的每日文件太没有事件逻辑了，然后又觉得直接按照事件逻辑写又会让自己之前对于这个daydayup的文件的初衷好像有些许违背.

# 萌生想法
所以我萌生出了一个想法:
- 就是写一个脚本让我每天写的东西自动按名称分类到各个事件集上（但是这是一个无序到有序的熵减的过程，实现起来十分困难）

于是我又想到了反过来搞一发
- 就是我通过脚本判断文件的生成日期自动用脚本形成一个文件树，这样应该不会太难，对于修改文件的处理就是copy一份上一次修改的文件加上此次修改的内容，然后再生成一份文件到对于的日志文件

# 反思
> 当我正在写这个文档的时候，我突然发现我的现在这个想法不就是git仓库的冗余版本吗?
所以这样的冗余好像确实是很浪费资源的，而且没有很大必要，所以我觉得以后还是使用事件性的描述文件形式吧，因为如果想要查看某个文件的修改历史就直接使用`git log filename`就完事了.   ---> 想要看每天交了多少提交量也可以用git...

# 深思
原来自己的一些幼稚的想法早已被前人深度实现了，所以自己当下的技术水平应该做的不是去自己一个人盲目探索，而是要多学习他人沉淀下来的知识，这样才能更快得成长为一个技术专家！

# 加油
好的，既然今天2019年11月17日14:24:21 发现了这个方法，那就好好努力吧

# git.sh执行太久
`find . -name "*.out" | xargs rm -rf` 怀疑是这句话搜索的不是本地...而是搜索了整个文件系统

然后改成了`find /Users/linmin/Documents/WolfEat3moreMeatEveryday -name "*.out" | xargs rm -rf` 就快了很多

但是自己写 test.sh 去输出 `.`,同样用bash调用,却并没有发现目录奇怪......所以为什么之前的命令卡很久就成了一个迷..
