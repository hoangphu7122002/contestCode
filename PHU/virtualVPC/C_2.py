n = int(input())

data = [[0, 0] for i in range(n)]

for i in range(n):
    c, a = input().split()
    data[i] = [c, int(a)]
    
a = [ele[1] for ele in data]
c = [ele[0] for ele in data]
count = 0
check = [False for i in range(n)]

for i in range(n):
    if check[i] == True: continue
    if c[i] == 'n': continue
    check[i] = True
    max_n = -1
    save_idx = n
    for j in range(i + 1,n):
        if check[j] == True: continue
        if c[j] == 'n' and a[j] >= a[i]:
            # max_n = a[j]
            save_idx = j
            break
        elif c[j] == 'n' and a[j] > max_n:
            max_n = a[j]
    
    flag = False
    a_check = [False for i in range(n)]
    for j in range(i + 1,save_idx):
        if check[j] == True: continue
        if c[j] == 'y' and a[j] > max_n:
            check[j] = True
            flag = True
            a_check[j] = True
    
    flag2 = False
    for j in range(i + 1, save_idx):
        if c[j] == 'n': break
        check[j] = True
        if a_check[j] == False: flag2 = True
    
    if flag == False:
        count += 1
    elif flag2 == False:
        count += 1
    else:
        count += 2

print(count)
        
    
    
            