s = input()
ans = 0
se = set()

# for i in range(10):
#     print(i)

for _ in s:
    tp = ord(_)-ord('0')
    if tp in se:
        continue
    else:
        se.add(tp)
        ans = ans + tp

print(ans)