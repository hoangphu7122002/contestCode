T = int(input())
XKs = [[0,0] for i in range(T)]
for i in range(T):
    XKs[i] = [int(i) for i in input().split()]
    
for X,K in XKs:
    smallest = int(X*2)
    biggest = int(X*K*(X*K-1))
    print(smallest, biggest)