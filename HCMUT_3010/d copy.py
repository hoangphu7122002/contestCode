N, M = [int(i) for i in input().split()]
mapp = ['' for j in range(N)]


for i in range(N):
    mapp[i] = input() 

q = []

candidates = [[0,0,'']]
path = mapp[0][0]
def find_path(i,j,path):
    for i in range(N):
        for j in range(M):
            if -ord(mapp[i+1][j]) > -ord(mapp[i][j+1]):
                i+=1
                path+=mapp[i][j]
            elif -ord(mapp[i+1][j]) < -ord(mapp[i][j+1]):
                j+=1
                path+=mapp[i][j]
            else: 
                candidates.append([i+1,j,path+mapp[i+1][j]])
                candidates.append([i,j+1,path+mapp[i][j+1]])
    return path