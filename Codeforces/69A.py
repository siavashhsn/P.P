a = input()
c = [0, 0, 0]
for i in range(int(a)):
    b = [int(i) for i in input().split()]
    c[0] += b[0]
    c[1] += b[1]
    c[2] += b[2]

if c[0]==0 and c[1]==0 and c[2]==0:
    print("YES")
else:
    print("NO")