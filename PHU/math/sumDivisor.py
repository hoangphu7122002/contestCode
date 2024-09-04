import math
n = int(input())

S = n % (10**9+7)
S += (n-(n//2+1)+1)*(n//2+1+n)//2 % (10**9+7) if n > 1 else 0
# print(S)

# prev_n_multiple_of_i = None
# i = 2
# # for i in range(2, int(math.sqrt(n))+1):
# while True:
#     # print(i)
#     n_multiple_of_i = n//i
#     if n_multiple_of_i > i:
#         S += n_multiple_of_i * i * 2 % (10**9+7)
#     else:
#         # print("here we go")
#         S += n_multiple_of_i * i % (10**9+7)
        
#     # print(S)
        
#     if not prev_n_multiple_of_i is None and n_multiple_of_i>=i:
#         # print(prev_n_multiple_of_i)
#         # print(n_multiple_of_i)
#         # print(i)
#         S += (prev_n_multiple_of_i + n_multiple_of_i)//2 * (prev_n_multiple_of_i - n_multiple_of_i - 1) * (i-1) % (10**9+7)
    
#         # print("ttttt", S)
#     prev_n_multiple_of_i = n_multiple_of_i
    
#     i += 1
#     if n_multiple_of_i <= i:
#         break

left = 2
while True:
    right = n//(n//left)
    # print(left, right)
    if right > n//2:
        break
    
    S += (right - left + 1) * (right + left) // 2 * (n//left) % (10**9+7)
    # print(S)
    left = right+1
    


print(S % (10**9+7))