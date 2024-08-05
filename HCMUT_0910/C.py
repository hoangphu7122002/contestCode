import bisect
n_test = int(input())
tests = []
for _ in range(n_test):
    n = int(input())
    arr = [int(i) for i in input().split()]
    tests.append([n,arr])
for n,arr in tests:
    arr.sort()
    count = 0
    for i_d in range(n-1,2,-1):
        for i_c in range(i_d-1,1,-1):
            ab = arr[i_d]/arr[i_c]
            if ab!=int(ab): continue
            for i_a in range(0, i_c):
                b = ab/arr[i_a]
                if b!=int(b): continue
                else:
                    l = bisect.bisect_left(arr, b, i_a+1, i_c)
                    r = bisect.bisect_right(arr, b,i_a+1,i_c)
                    # print(l,r,i_c,i_d)
                    if arr[l]==b:
                        count += r-l
    print(count)