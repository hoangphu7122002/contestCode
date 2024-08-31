maxN = int(1e3 + 1)
maxM = int(1e3 + 1)

a = [0] * maxN

# Index that is out of bounds for the array 'a'
idx = int(1e7)

# This will raise an IndexError in Python because 'idx' is larger than the array size
print(a[idx])