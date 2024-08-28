n, k = [int(i) for i in input().split()]

import math
a = math.ceil(n/k)

print(int(a*(a+1)/2))
