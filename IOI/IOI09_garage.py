from collections import deque
d = deque()
 
n,m = map(int, input().split())
rates = []
weights = []
for i in range(n):
    rates.append(int(input()))
 
for i in range(m):
    weights.append(int(input()))
 
ans = 0
spots = [-1 for i in range(n)]
 
for i in range(2*m):
    a = int(input())
    if a>0:
        d.append(a)
    else:
        a = -a
        for i in range(n):
            if spots[i] == a:
                spots[i] = -1
                break
    while len(d):
        sus = d.popleft()
        realsus = False
        for i in range(n):
            if spots[i] == -1:
                realsus = True
                spots[i] = sus
                ans += weights[sus-1]*rates[i]
                break
        if realsus == False:
            d.appendleft(sus)
            break
    
        
print(ans)