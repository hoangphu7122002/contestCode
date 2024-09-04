import bisect

n, t = list(map(int, input().split()))
x = list(map(int, input().split()))

prefix_sum = [0 for _ in range(len(x)+1)]

for i in range(1, len(prefix_sum)):
    prefix_sum[i] = prefix_sum[i-1] + x[i-1]
    
# print(prefix_sum)

S = 0
for i in range(len(prefix_sum)):
    search_value = prefix_sum[i] + t
    search_index = bisect.bisect_right(a=prefix_sum, x=search_value, lo=i, hi=len(prefix_sum))
    # print(i, search_index)
    S += (search_index - i - 1)
    
print(S)
    