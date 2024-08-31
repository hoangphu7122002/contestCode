N = int(input())
A = list(map(int, input().split(' ')))
X = int(input())

sum_A = sum(A)
num_dup = X//sum_A
remainder = X % sum_A

prefix_sum_A = 0
for i, a in enumerate(A, 1):
    prefix_sum_A += a
    # print(i)
    # print(prefix_sum_A)
    if prefix_sum_A > remainder:
        break

print(num_dup*len(A)+i)
