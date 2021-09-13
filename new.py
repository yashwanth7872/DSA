def maxcollected(i,n,k,l):
    if i>=n: return 0
    left = maxcollected(i+1,n,k,l)
    right = l[i] + maxcollected(i+1+k,n,k,l)
    return max(left,right)

n,k = (map(int,input().split(",")))
l = list()
for i in range(n):
    l.append(int(input()))

print(maxcollected(0,n,k,l))

    

