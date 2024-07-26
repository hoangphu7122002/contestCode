
def solver(n,K,a):
    s = sum(a)
    K = K%s
    for i in range(n):
        x = a[i]
        if K<x: return K
        else: K-=x

if __name__ == "__main__":
    with open("BONUS.INP") as f:
        n, K = [int(i) for i in f.readline().strip().split()]
        a = [int(i) for i in f.readline().strip().split()]
    out = str(solver(n,K,a))
    with open("BONUS.OUT", "w") as f:
        f.write(out)
        