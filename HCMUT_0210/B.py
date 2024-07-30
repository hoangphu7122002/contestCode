import io,os
n = int(input())
strings = []
for i in range(n):
    strings.append(input())
num_CSE = 0
for s in strings:
    flag_C = False
    flag_S = False
    for c in s:
        if not flag_C:
            if c == 'C':
                flag_C = True
        else:
            if not flag_S:
                if c == 'S':
                    flag_S = True
            else:
                if c == 'E':
                    num_CSE += 1
                    break
print(num_CSE)