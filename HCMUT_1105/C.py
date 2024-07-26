def solver(s):
    l = []
    streak0 = 0
    l_s = len(s)
    for i in range(l_s):
        c=s[i]
        if c=='0':
            streak0 += 1
        else:
            l.append(streak0)
            streak0 =0
        if i==l_s-1:
            l.append(streak0)
    # print(l)
    if len(l)<=3: return sum(l)+3
    else:
        sum_quad = []
        for i in range(len(l)-3):
            sum_quad.append(sum(l[i:i+3]))
        return max(sum_quad)+3
    
if __name__ == '__main__':
    with open("BEST_K.INP") as f:
        s = f.read()
    with open("BEST_K.INP","w") as f:
        f.write(str(solver(s)))