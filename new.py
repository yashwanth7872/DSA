


def maxi(s):
    l = s.split()
    maxi = 0
    result = ""
    for i in l:
        n = len(i)
        if(n%2==0):
            if(maxi < n):
                maxi = n
                result = i
    return result

print(maxi("It is a pleasant day today"))

    

