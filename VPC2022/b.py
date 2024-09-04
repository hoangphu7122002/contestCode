def findLargestSpace(m, n, positions):
    # Write your code here
    positions = sorted(positions)
    
    dist = [0 for i in range(len(positions)-1)]
    for i in range(0, len(positions)-1):
        dist[i] = positions[i+1] - positions[i]
        
    return max(dist)

m = 5
n = 3
positions = [4, 0, 1]

print(findLargestSpace(m, n, positions))