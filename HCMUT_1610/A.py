n = int(input())
l = [[] for i in range(n)]
for i in range(n):
    l[i] = input().split()
    
n_printed = 0
d = {}
for i in range(n):
    if d.get(l[i][0], "N") =="N":
        d[l[i][0]] = "Y"
        print(l[i][0]+' '+l[i][1])
        n_printed += 1
        if n_printed == 12:
            break
    