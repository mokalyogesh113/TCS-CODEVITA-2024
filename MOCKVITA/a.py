def f(a=8,b=9):
    if(a<b):
        return f(b,a)
    elif(b!=0):
        return (a+f(a,b-1))
    return 0

print(f())






