import math
n = int(input())

S = n % (10**9+7) 
S += (n//2+1) % (10**9+7) if n%2 == 1 else n//2

# print(S)

prev_n_multiple_of_i = None
for i in range(2, int(math.sqrt(n))+1):
    # print(i)
    n_multiple_of_i = n//i
    if n_multiple_of_i != i:
        S += n_multiple_of_i % (10**9+7) + i % (10**9+7)
    else:
        S +=  n_multiple_of_i % (10**9+7)
    if not prev_n_multiple_of_i is None:
        S +=  (prev_n_multiple_of_i - n_multiple_of_i - 1)* (i-1) % (10**9+7)
    prev_n_multiple_of_i = n_multiple_of_i
    

print(S % (10**9+7))