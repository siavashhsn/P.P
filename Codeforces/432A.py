a, b = map(int, input().split())
c = [int(i) for i in input().split()]
sorted(c)
d=0
e=0
for i in range(len(c)):
	if e<3:
		if c[i]+b <= 5:
			e+=1
	else:
		d+=1
		e=0
		if c[i]+b <= 5:
			e+=1
if e==3:
	d+=1
print(d)
