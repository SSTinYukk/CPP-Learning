def fenduan(x):
    if(x<=-2):
        x=-2*x-1
    elif(x>1):
        x=x*2+1
    else:
        x=3
    return x

try:
    x=float(input())
except ValueError:
    print("Input Error")
    exit()
y=fenduan(x)
print("y=%.2f" %(y))

