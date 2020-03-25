if __name__ == "__main__":
    input_list = input()[1:-1].split(',')
    # 下面这一步不知道为什么能过浮点型，但确实能过...因为字符串比较...
    # [1,3,6,8,8.5,0.5,0.9,8.1,0,'a','...',9,9,9,10,-1] 找个-1,就wa了
    list_int_m = [eval(i) for i in input_list if '0'<=i<='9']

    # 去重应该是不能去重的
    list_int = sorted(set(list_int_m), key=list_int_m.index)
    print(list_int)
    output_list = []
    list_len = len(list_int)
    for i in range(list_len):
        for j in range(i,list_len):
            if list_int[i] + list_int[j] == 9:
                output_list.append((list_int[i],list_int[j]))
    print(output_list)