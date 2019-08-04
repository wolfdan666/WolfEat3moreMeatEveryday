T=int(input())
for t in range(T):
    b=input()
    a=[]
    for i in range(8):
        # 这个[2:]是去掉'0x'
        a.append(hex(int(b[i*16:i*16+16],2))[2:])
    s=[]
    s.append(':'.join(a))
    for i in range(8):
        for j in range(i+1,8):
            # 对每个i中的后缀长a[i:j+1]判断各元素是否都是等于0的
            # 是就直接把字符串丢进去,比C++AC版本中的记录长度简单很多
            if all(map(lambda x:x=='0',a[i:j+1])):
                # 用':'分隔的a[i]串
                s.append(':'.join(a[:i])+'::'+':'.join(a[j+1:]))
    # 优先用长度排序,其实是同长度按照字典序排序
    s.sort(key=lambda x:(len(x),x))
    print('Case #%d:'%(t+1),s[0])