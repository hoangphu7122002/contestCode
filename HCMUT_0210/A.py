with open('DECIPHER.INP','r') as f:
    line = f.read()

num_dict = {}
prev_is_char = True
cur_num = ''
for i in range(len(line)-1):
    if line[i].isnumeric():
        prev_is_char = False
        cur_num += line[i]
    else:
        if prev_is_char==False:
            num_dict[cur_num]=False
            cur_num = ''
            prev_is_char = True

i+=1
if line[i].isnumeric():
    cur_num += line[i]
    num_dict[cur_num]=True
elif prev_is_char==False:
    num_dict[cur_num]=True
    
num_dist_num = len(list(num_dict.keys()))
# print(num_dict)
with open('DECIPHER.OUT','w') as f:
    f.write(str(num_dist_num))