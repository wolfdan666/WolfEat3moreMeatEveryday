'''
[8.5,0.5]
[1,3,6,8]
[1,3,6,8,8.5,0.5,0.9,8.1,0,'a','...',9]
[1,3,6,8,8.5,0.5,0.9,8.1,0,'a','...',9,9,9]
[0,'a','...',9]
[0.9,8.1]
由于自己对于python判断是否为数字的生疏，导致这题写了接近90分钟...
'''

s_list = eval(input())

n = len(s_list)

ans = []
def is_number(s):
    try:  # 如果能运行float(s)语句，返回True（字符串s是浮点数）
        float(s)
        return True
    except ValueError:  # ValueError为Python的一种标准异常，表示"传入无效的参数"
        pass  # 如果引发了ValueError这种异常，不做任何事情（pass：不做任何事情，一般用做占位语句）
    return False


for i in range(n):
    for j in range(i+1,n):
        if is_number(s_list[i]) and is_number(s_list[j]):
            tp = abs(s_list[i]+s_list[j] - 9)
            if tp < 1.0e-9:
                ans.append((s_list[i],s_list[j]))

print(ans)