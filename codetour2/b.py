import math

M = int(input())
primes = []

for i in range(2, int(math.sqrt(M))+1):
    already_appended = False
    while M%i == 0:
        if not already_appended: 
            primes.append(i)
            already_appended = True
        
        M //= i

if M != 1:
    primes.append(M)

# print(primes)
for i in range(len(primes)):
    primes[i] %= 26
    
primes = sorted(primes)

for prime in primes:
    print(chr(prime+65), end="")