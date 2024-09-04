n = int(input())
commands = ['' for i in range(n)]
for i in range(n):
    commands[i] = input().split()
stack = [0 for i in range(n+1)]
stack[0] = 1
stack_ind = 1
s=0
of = False
for command in commands:
    if command[0]=='for':
        f = int(command[1])
        stack[stack_ind] = stack[stack_ind-1]*f
        stack_ind+=1
    elif command[0]=='add':
        s+=stack[stack_ind-1]
        # print(stack, s, stack_ind)
        if s>=2**32: 
            print("OVERFLOW!!!")
            of = True
            break
    elif command[0]=='end':
        stack[stack_ind] = 0
        stack_ind-=1
if not(of):
    print(s)
        
        
        