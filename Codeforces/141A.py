a = input()
b = input()
c = input()

a = sorted(a)
b = sorted(b)
c = sorted(c)

d=True
e=True
for x in a:
	if x in c:
		c.remove(x)
	else:
		d=False
		break

for x in b:
	if x in c:
		c.remove(x)
	else:
		e=False
		break

if(len(c)==0 and d == True and e == True):
	print("YES")
else:
	print("NO")