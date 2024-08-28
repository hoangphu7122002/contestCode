import math

N = int(input())
a_ls = list(map(int,input().split()))

T = int(input())
data = [_ for _ in range(T)]

for i in range(T):
    X,P = list(map(int,input().split()))
    data[i] = X, P

def to_prime_factor(ls, min_divisor):
    a_prime_dict = {}
    for a in ls:
        while a != 1:
            if min_divisor[a-1] in a_prime_dict.keys():
                a_prime_dict[min_divisor[a-1]] += 1
            else:
                a_prime_dict[min_divisor[a-1]] = 1

            a //= min_divisor[a-1]
    return a_prime_dict

    
X_ls = [data[i][0] for i in range(T)]

upper = max(a_ls+X_ls)

min_divisor = [i for i in range(1, upper+1)]

for i in range(1, int(math.sqrt(len(min_divisor)))+1):
    if min_divisor[i] == i+1: # prime
        for j in range(min_divisor[i]**2-1, len(min_divisor), min_divisor[i]):
            min_divisor[j] = min_divisor[i]
    

# print(min_divisor)

a_prime_dict = to_prime_factor(a_ls, min_divisor)

# print(a_prime_dict)

output = [1 for _ in range(T)]

for i, (X, P) in enumerate(data):
    X_prime_dict = to_prime_factor([X], min_divisor)
    XP_prime_dict = {k:v*P for k,v in X_prime_dict.items()}
    # print(XP_prime_dict)
    
    for k in XP_prime_dict.keys():
        if k not in a_prime_dict.keys():
            output[i] = 0
            break
        elif XP_prime_dict[k] > a_prime_dict[k]:
            output[i] = 0
            break
        
print(''.join([str(o) for o in output]))
    