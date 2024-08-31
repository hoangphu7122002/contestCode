t = int(input())

data = [[0, 0] for i in range(t)]

for i in range(t):
    a, b = list(map(int, input().split()))
    
    data[i] = a, b
    
for a, b in data:
    if (a + b) % 2 == 0:
        print("Bob")
    else:
        print("Alice")