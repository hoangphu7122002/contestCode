def solver(n, arr):
    min_int  = 1e9
    max_neg = -1e9
    s = 0
    num_num = 0
    for num in arr:
        if num>=0: 
            s+=num
            num_num+=1
            if min_int>num: min_int=num
        elif max_neg<num: max_neg=num
    if num_num%2==1:
        if max_neg!=-1e9 and min_int+max_neg >0:
            s+=max_neg
        else:
            s-=min_int
    return s
if __name__ =='__main__':
    n = int(input())
    arr = [int(i) for i in input().split()]
    print(solver(n, arr))
            