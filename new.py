t = int(input())
while(t):
    s = input()
    if(s == '9'):
        print(1)
    elif(len(s)==1):
        print(0)
    else:
        print(s[:-1])