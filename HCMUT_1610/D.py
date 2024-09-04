n, k = map(int, input().split())
data = [0 for _ in range(k)]
for i in range(k):
    op, x1, x2 = input().split()
    data[i] = op, int(x1)-1, int(x2)-1


def get_prefix_sum(x):
    S = 0
    for i in range(len(x)):
        S += x[i]
        x[i] = S
    return x
    
delta_R = [0 for _ in range(n)]
delta_D = [0 for _ in range(n)]
delta2_H = [0 for _ in range(n)]
delta2_V = [0 for _ in range(n)]

try:
    for i in range(k):
        op, x1, x2 = data[i]
        if op == 'R':
            delta_R[x1] += 1
            if x2+1 < n:
                delta_R[x2+1] += -1  
        elif op == 'D':
            delta_D[x1] += -1
            if x2+1 < n:
                delta_D[x2+1] += 1
        elif op == 'H':
            # pass
            delta2_H[x1] += 1
            if x2+1 < n:
                delta2_H[x2+1] += -(x2-x1) + 1
            if x2+2 < n:
                delta2_H[x2+2] += 1
            if x2+(x2-x1)+1 < n:
                delta2_H[x2+(x2-x1)+1] += -(x2-x1) + 1
        elif op == 'V':
            # pass
            delta2_V[x1] += -1 
            if x2+1 < n:
                delta2_V[x2+1] += (x2-x1) - 1
            if x2+2 < n:
                delta2_V[x2+2] -= 1
            if x2+(x2-x1)+1 < n:
                delta2_V[x2+(x2-x1)+1] += (x2-x1) - 1
except IndexError:
    print("Hi", op, x1, x2)
            
prefix_sum_R = get_prefix_sum(delta_R)
prefix_sum_D = get_prefix_sum(delta_D)

prefix_sum_H = get_prefix_sum(get_prefix_sum(delta2_H))
prefix_sum_V = get_prefix_sum(get_prefix_sum(delta2_V))

output = [0 for _ in range(n)]
for i in range(n):
    output[i] = prefix_sum_R[i] + prefix_sum_D[i] + prefix_sum_H[i] + prefix_sum_V[i]
    
for x in output:
    print(x)
            

        