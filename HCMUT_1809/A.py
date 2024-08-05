with open("WIFIPASS.INP", "r") as f:
    inp = f.readlines()
    Q =  int(inp[0])
    Ns = [int(i) for i in inp[1:]]
ans=[]
for N in Ns:
    N2p1 = N*N+1
    max_ = 0
    x,y =0,0
    for i in range(2,N+2):
        j = N2p1//i
        if j*i==N2p1: 
            if i+j > max_: 
                max_ = i+j
                x,y = i,j
                break
    # if x <= y:
    ans.append(str(int(x-1))+str(int(y-1)))
    # else:
    #     ans.append(str(int(y-1))+str(int(x-1)))
with open("WIFIPASS.OUT", "w") as f:
    for a in ans:
        f.write(a+'\n')