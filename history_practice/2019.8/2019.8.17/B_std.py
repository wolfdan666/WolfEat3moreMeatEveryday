# python3

lf = [0, 6, 7]
# 一千多项的时候远远超过了10^12+7的
for _ in range(1000) :
    lf.append(lf[-2] + lf[-1])
    # if _ == 999:
    #     print(If[-1])

def f(x, s) :
    if x == 1 :
        return "COFFEE"[s]
    if x == 2 :
        return "CHICKEN"[s]
    if s >= lf[x-2] :
        return f(x - 1, s - lf[x - 2])
    else :
        return f(x - 2, s)

for _ in range(eval(input())) :
    n, s = map(int, input().split())
    s -= 1
    # 从s到min(s+10,lf[n]), 用中括号括起来生成列表
    r = [f(n, t) for t in range(s, min(s + 10, lf[n]))]
    print(''.join(r))
