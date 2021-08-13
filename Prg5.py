flag=0
locks=int(input("Enter the total number of locks"))
stocks=int(input("Enter the total number of stocks"))
barrels=int(input("Enter the total number of barrels"))
if locks<0 or locks>70 or stocks<0 or stocks>80 or barrels<0 or barrels>90:
    flag=1
if flag==1:
    print("invalid input")
    exit()
totalsales=(locks*45.0)+(stocks*30.0)+(barrels*25.0)
if totalsales<1000:
    commission=0.10*totalsales
elif totalsales<1800:
    commission=0.10*1000
    commission=commission+(0.15*(totalsales-1000))
else:
    commission=0.10*1000
    commission=commission+(0.15*800)
    commission=commission+(0.20*(totalsales-1800))
print("The totalsale is %d",totalsales)
print("The commission is %f",commission)