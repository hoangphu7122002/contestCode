# def solver(n, d, s, X, ind):
#     if ind==n-1: 
#         s+=X[ind]
#         if d.get(s, False): 
#             return 1
#         else: return 0
#     else:
#         s+=X[ind]
#         exist = d.get(s, False)
#         if exist: return solver(n, d, '', X, ind+1) +solver(n, d, s, X, ind+1)
#         else: return solver(n, d, s, X, ind+1)

n = int(input())
S = [input() for i in range(n)]
X = input()
d = {}
for s in S:
    d[s] = 1
l = len(X)
# print(solver(len(X), d, '', X, 0))
dp = [[-1 for i in range(l)] for j in range(l)]
for i in range(l):
    dp[i][i]=d.get(X[i], 0)
for i in range(l):
    
    for j in range(1,l-i):
        dp[i][i+j]= dp[i][i+j-1]+d.get(X[j],0)
print(dp[0][l-1])