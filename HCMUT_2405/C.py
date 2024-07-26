def bin_search_lower(x, start, end, arr):
    if x>arr[end-1]: return 0
    if x<=arr[start]: return start
    mid = (start + end) // 2
    if x >= arr[mid]:
        return bin_search_lower(x, start, mid , arr)
    else:
        return bin_search_lower(x, mid , end, arr)

def bin_search_upper(x, start, end, arr):
    if x<arr[start]: return 0
    if x>=arr[end-1]: return end
    mid = (start + end) // 2
    if x <= arr[mid]:
        return bin_search_upper(x, start, mid , arr)
    else:
        return bin_search_upper(x, mid , end, arr)

if __name__ == '__main__':
    # print(bin_search_lower(1,0,0,[2]))
    # print(bin_search_upper(4,0,2,[3,4,6]))
    n = int(input())
    arr = [int(i) for i in input().split()]
    
    darr = {}
    for num in arr:
        darr[num] =[[],0]
    for i in range(n):
        darr[arr[i]][0].append(i)
        darr[arr[i]][1]+=1
    
    print(darr)
    Q = int(input())
    qlrs = []
    for i in range(Q):
        qlrs.append([int(j) for j in input().split()])
        
    for q,l,r in qlrs:
        ids = darr.get(q, 0)
        if ids==0:
            print(0)
            continue
        else:
            lower = bin_search_lower(l-1,0,ids[1],ids[0])
            upper = bin_search_upper(r-1,0,ids[1],ids[0])
            print(upper-lower)