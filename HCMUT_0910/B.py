import bisect

n, r = map(int, input().split())
d_list = list(map(int, input().split()))

# n, r = 5000, 2
# d_list = [i for i in range(5000)]

# left = 0
# right = 1

output = 0

# while right <= n-1:
#     dist = d_list[right] - d_list[left]
#     if dist > r:
#         # print(left, right)
#         output += n-right
#         left += 1
#     else:
#         right += 1
        
# print(output)

left = 1

for i in range(len(d_list)):
    index = bisect.bisect_right(d_list, d_list[i] + r, left, len(d_list))
    output += n - index
    left = index
    
print(output)
    