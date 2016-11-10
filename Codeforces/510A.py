# b = [int(i) for i in input().split()]
c, b = map(int, input().split())
d = 1
a = 1
for i in range(c):
    if(a):
        print("#"*b)
        a=0
    else:
        if(d):
            print("."*(b-1)+"#")
            d=0
        else:
            print("#"+"."*(b-1))
            d=1
        a=1
