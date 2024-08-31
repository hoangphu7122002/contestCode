for _ in ['01','02','03','04','05','06','07','08','09','10']:
    with open(_+'.inp','r') as f:
        n,m,k = [int(i) for i in f.readline().strip().split()]
        mapp = [['#']*(m)]*(n)
        x,y = 0,0 #x vertical, y horizontal
        found_start =False
        
        #map
        for i in range(n):
            line = [c for c in f.readline().strip()]
            mapp[i] = line
            
            if not found_start:
                try:
                    y_ = line.index('O')
                except: 
                    y_=-1
                if y_!=-1:
                    y=y_
                    x=i
                    found_start = True

    i,j = x,y
    # print(i,j)
    seq = ''
    step_taken = 0
    while step_taken < k:
        
        best_act = 'R'
        max_undiscover = 0
        #right
        # print(i,j)
        if mapp[i][j+1] != '#':
            
            undiscover = 1
            j_ = j+2
            while mapp[i][j_] !='#':
                if mapp[i][j_] == '.':
                    undiscover+=1
                j_+=1
            if max_undiscover < undiscover: 
                best_act = 'R'
                max_undiscover = undiscover
        #Up
        if mapp[i-1][j] != '#':
            undiscover = 1
            i_ = i-2
            while mapp[i_][j] !='#':
                if mapp[i_][j] == '.':
                    undiscover+=1
                i_-=1
            if max_undiscover < undiscover: 
                best_act = 'U'
                max_undiscover = undiscover  
        #Left
        if mapp[i][j-1] != '#':
            undiscover = 1
            j_ = j-2
            while mapp[i][j_] !='#':
                if mapp[i][j_] == '.':
                    undiscover+=1
                j_-=1
            if max_undiscover < undiscover: 
                best_act = 'L'
                max_undiscover = undiscover
        #down
        if mapp[i+1][j] != '#':
            undiscover = 1
            i_ = i+2
            while mapp[i_][j] !='#':
                if mapp[i_][j] == '.':
                    undiscover+=1
                i_+=1
            if max_undiscover < undiscover: 
                best_act = 'D'
                max_undiscover = undiscover 
        
        seq+=best_act
        step_taken+=1
        
        if best_act =='R':
            j_ = j+1
            while mapp[i][j_] !='#':
                mapp[i][j_] = 'X'
                j_+=1
            j = j_-1
        elif best_act =='U':
            i_ = i-1
            while mapp[i_][j] !='#':
                mapp[i_][j] = 'X'
                i_-=1
            i = i_+1      
        elif best_act =='L':
            j_ = j-1
            while mapp[i][j_] !='#':
                mapp[i][j_] = 'X'
                j_-=1
            j = j_+1
        else: #'D'
            i_ = i+1
            while mapp[i_][j] !='#':
                mapp[i_][j] = 'X'
                i_+=1
            i = i_-1     
        # for line in mapp:
        #     print(line)
        # print(max_undiscover, best_act)
    with open(_+'.out','w') as f:
        f.write(seq)