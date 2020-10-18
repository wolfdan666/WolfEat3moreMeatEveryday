''' 第一种本地是ok的，但是oj会RE...
第二种才能AC
可能先eval再str的过程会导致一些信息丢失吧
或者是oj的py3的版本问题，不管了
if __name__ == "__main__":
    user_input = eval(input())
    N_list = set(map(int,str(user_input)))
    sum = 0
    for i in N_list:
        sum += i
    print(sum)
'''


if __name__ == "__main__":
    user_input = input()
    N_list = set(map(int,user_input))
    sum = 0
    for i in N_list:
        sum +=i
    print(sum)
