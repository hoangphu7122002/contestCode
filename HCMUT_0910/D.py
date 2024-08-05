import math

expression = input()

def calculate(operator, a, b):
    if operator == 'SUM':
        return a + b
    elif operator == 'DIF':
        return a - b
    elif operator == 'MAX':
        return max(a, b)
    elif operator == 'MIN':
        return min(a, b)
    elif operator == 'GCD':
        return math.gcd(a, b)

prev_pointer = 0
pointer = 2
stack = [[expression[prev_pointer:pointer+1]]]
prev_pointer = pointer + 2 # skip 1st ( 
pointer += 2 # skip 1st (

while len(stack) > 0:
    # print(pointer)
    char = expression[pointer]
    # print(char)
    if not char in ['(', ')', ',']:
        pointer += 1
    else:
        element = expression[prev_pointer:pointer]
        # print(element)
        # print(char)
        if element in ['MAX', 'GCD', 'SUM', 'MIN', 'DIF']:
            stack.insert(0, [element])
        elif len(element) > 0:
            stack[0].append(int(element))
        prev_pointer = pointer + 1 # skip 1st ( 
        pointer += 1 # skip 1st (        
        
        # print(stack[0])
        
    while len(stack[0]) == 3:
        
        result = calculate(stack[0][0], stack[0][1], stack[0][2])
        stack.pop(0)
        if len(stack) > 0:
            stack[0].append(result)
        else:
            break        
    
print(result)
