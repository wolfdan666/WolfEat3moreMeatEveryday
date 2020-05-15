#import itertools
def GetAllSeq(input, i, stk, tmp, res):
    # 注意tmp1和stk是要回溯的，所以这两者不能传引用；而res是一直保留结果的，传引用就对
    tmp1 = list(tmp)
    stk1 = list(stk)
    if i == len(input): # 结果记录
        stk1 = stk1[::-1]
        tmp1.extend(stk1)
        res.append(tmp1)
        #print(res)
        return
    stk1.append(input[i]) # 先将当前字母入栈，然后后面选择继续递归入栈或者出栈
    GetAllSeq(input, i+1, stk1, tmp1, res) #继续遍历
    while stk1: # 一个个出栈
        #tmp = []
        # 出栈一个之后遍历进入下一个，或者是出栈多个之后遍历进入下一个i+1
        tmp1.append(stk1[-1])
        stk1.pop()
        GetAllSeq(input, i+1, stk1, tmp1, res)



input = 'abc'
res = []
stk = ''
tmp = ''
GetAllSeq(input, 0, stk, tmp, res)
print(res)
res = [''.join(x) for x in res]
# 法一
res = list(set(res))
res.sort()
print(res)
# 法二
#res = itertools.groupby(res)

# 法三 dict去重并保留顺序
# res = list(dict.fromkeys(res))
# print(res)