N, M = [int(i) for i in input().split()]
mapp = ['' for j in range(N)]


for i in range(N):
    mapp[i] = input() 

def compare(s1,s2):
    for i in range(N+M-1):
        if -ord(s1[i]) > -ord(s2[i]):
            return s1
        elif -ord(s1[i]) < -ord(s2[i]):
            return s2
    return s1
def f(i,j,path):
    path+=mapp[i][j]
    if i == N-1 and j == M-1:
        return path
    if i==N-1:
        return f(i, j+1, path)
    if j==M-1:
        return f(i+1, j, path)
    if -ord(mapp[i+1][j]) > -ord(mapp[i][j+1]):
        return f(i+1, j, path)
    elif -ord(mapp[i+1][j]) < -ord(mapp[i][j+1]):
        return f(i, j+1, path)
    else:
        return compare(f(i+1, j, path),f(i, j+1, path))

print(f(0,0,''))