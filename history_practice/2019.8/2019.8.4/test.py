a=[]
b=input()
for i in range(8):
    # 这个[2:]不会是去掉'0x'吧？
    print(int(b[i*16:i*16+16],2))
    a.append(hex(int(b[i*16:i*16+16],2)))
print(a)