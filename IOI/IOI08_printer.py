n = int(input())
 
 
def compare(a,b):
    sus = 0
    for i in range(min(len(a),len(b))):
        if a[i]==b[i]:
            sus += 1
        else:
            break
    return sus
 
 
words = dict()
for i in range(n):
    words[input()] = 0
 
maxi = ""
 
for i in words:
    if len(i) > len(maxi):
        maxi = i
suswords = dict()
 
for i in words:
    words[i] = compare(i, maxi)
 
lis = [i for i in words]
 
lis.sort(key=lambda x: (words[x], x))
 
ans = 1
 
cur = []
for i in range(len(lis)-1):
    for j in lis[i][len(cur):]:
        cur.append(j)
        ans += 1
    ans += 1
    for i in lis[i][compare(lis[i], lis[i+1]):][::-1]:
        ans += 1
        cur.pop()
for j in lis[-1][len(cur):]:
    ans += 1
 
 
print(ans)
cur = []
for i in range(len(lis)-1):
    for j in lis[i][len(cur):]:
        cur.append(j)
        print(j)
    print("P")
    for i in lis[i][compare(lis[i], lis[i+1]):][::-1]:
        print("-")
        cur.pop()
for j in lis[-1][len(cur):]:
    print(j)
print("P")