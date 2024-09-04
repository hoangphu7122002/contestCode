n, L, R = list(map(int, input().split()))
a = list(map(int, input().split()))

max_ele = max(a)
if max_ele < L: 
    print("Yes")
else:
    print("No")