def solver(d, k):
    sum_k = sum(d[:k])
    max_k = max(d[:k])
    output = 1 if max_k < sum_k * 0.5 else 0 
    for i in range(k, len(d)):
        max_k = max(d[i], max_k)
        sum_k = sum_k - d[i-k] + d[i]
        output += 1 if max_k < sum_k * 0.5 else 0
        
    return output
    
if __name__ == '__main__':
    with open("tri.inp") as f:
        input = f.readlines()
        print(input)
        n, k = map(int, input[0].strip().split())
        d = list(map(int, input[1].strip().split()))
        
    with open("tri.out","w") as f:
        f.write(str(solver(d, k)))