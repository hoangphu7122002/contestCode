import math
n = int(input())
nps = []
pss =[]

for i in range(n):
    np = int(input())
    nps.append(np)
    ps=[]
    for j in range(np):
        ps.append([int(k) for k in input().split()])
    pss.append(ps)
for t in range(n):
    np = nps[t]
    ps = pss[t]
    
    max_dist = 0
    max_pair_ids = []
    for i in range(1,np):
        for j in range(i):
            dist = math.sqrt((ps[i][0]-ps[j][0])**2+(ps[i][1]-ps[j][1])**2)
            if dist > max_dist:
                max_dist = dist
                max_pair_ids = i,j
    print('---', max_dist)
    i,j = max_pair_ids
    a = ps[i][1] - ps[j][1]
    b = ps[j][0] - ps[i][0]
    c = ps[i][0]*ps[j][1] - ps[i][1]*ps[j][0]
    
    left_max_h = -1
    right_max_h = -1
    rand_p = [ps[i][0]+7, ps[i][1]+11]
    for k in range(n):
        if k==i or k==j: continue
        else:
            h = abs(a*ps[k][0] + b*ps[k][1] + c)/math.sqrt(a*a + b*b) 
            if (a*ps[k][0] + b*ps[k][1] + c) * (a*rand_p[0] + b*rand_p[1]+c) >0:
                if h > left_max_h:
                    left_max_h = h
            else:
                if h > right_max_h:
                    right_max_h = h
    print('---', left_max_h, right_max_h)
    print(left_max_h*max_dist*0.5+right_max_h*max_dist*0.5)
    
        