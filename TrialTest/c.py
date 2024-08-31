n = int(input())

data = [[0, 0] for i in range(n)]

for i in range(n):
    c, a = input().split()
    data[i] = [c, int(a)]
    
def num_del(data):
    if len(data) == 0:
        # print("1")
        return 0
    
    # print(data)
    
    no = [ca[1] for ca in data if ca[0] == 'n']
    if len(no) == 0:
        # print("2")
        return 1
    else:
        # print("3")
        max_no = max(no)
        
    num_yes_greater_than_max_no = 0
    smaller_than_max = [[]]
    
    for ca in data:
        if ca[0] == 'y' and ca[1] > max_no:
            # print("4")
            num_yes_greater_than_max_no += 1
        elif ca[0] == 'n' and ca[1] == max_no:
            # print("5")
            smaller_than_max.append([])
        else:
            # print("6")
            smaller_than_max[-1].append(ca)
    
    sum_per_region = []
    for region in smaller_than_max:
        sum_per_region.append(num_del(region))
        
    if num_yes_greater_than_max_no == 0:
        # print("7")
        return sum(sum_per_region)
    else:
        # print("8")
        return 1 + sum(sum_per_region)

# print("final")
print(num_del(data))