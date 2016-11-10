a = input()
b = input()
c = [0]*26
b = b.lower()
for i in b[:]:
    c[ord(i)-ord('a')] += 1
if[x for x in c if x == 0]:
    print("NO")
else:
    print("YES")

