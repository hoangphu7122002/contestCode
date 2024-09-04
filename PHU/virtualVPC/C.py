n = int(input())

data = [[0, 0] for i in range(n)]

for i in range(n):
    c, a = input().split()
    data[i] = [c, int(a)]
    
len_no = 0
def num_del(data):
    global len_no
    if len(data) == 0:
        return 0
    
    # print(data)
    
    no = [ca[1] for ca in data if ca[0] == 'n']
    len_no = len(no)
    if len(no) == 0:
        return 1
    else:
        max_no = max(no)
        
    num_yes_greater_than_max_no = 0
    smaller_than_max = [[]]
    
    for ca in data:
        if ca[0] == 'y' and ca[1] > max_no:
            num_yes_greater_than_max_no += 1
        elif ca[0] == 'n' and ca[1] == max_no:
            smaller_than_max.append([])
        else:
            smaller_than_max[-1].append(ca)
    
    sum_per_region = []
    for region in smaller_than_max:
        sum_per_region.append(num_del(region))
        
    if num_yes_greater_than_max_no == 0:
        return sum(sum_per_region)
    else:
        return 1 + sum(sum_per_region)
    
print(min(num_del(data),len_no + 1))
