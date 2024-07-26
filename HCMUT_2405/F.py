n = int(input())
S = [input() for i in range(n)]
X = input()

S = sorted(S)
avai_len_postfix = list(set(sorted([len(x) for x in S])))

res = [0 for i in range(len(X))]

for i in range(len(X)):
    score_string = X[:i+1]
    for len_post_fix in range(avai_len_postfix[0], min(avai_len_postfix[-1], len(score_string))):
        post_fix = X[-len_post_fix:]
        if post_fix in S:
            if res[i-len_post_fix] == 0:
                res[i] = 1
            else:
                res[i] += res[i-len_post_fix] % (10**9+7)
            
print(res[-1])
      