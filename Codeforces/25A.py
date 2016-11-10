b = input()
a = [int(i) for i in input().split()]

c = [a[0]%2, a[1]%2, a[2]%2]
z = 0
f = 0
for i in c:
    if i == 0:
        z += 1
    else:
        f += 1
if f > z:
    f = 1
else:
    f = 0
for i in range(len(a)):
    if a[i]%2 != f:
        print(i+1)
        break
