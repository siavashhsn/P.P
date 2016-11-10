from collections import OrderedDict

a = [int(i) for i in input().split()]
d = {}

for i in range(a[1]):
	b, c = map(int, input().split())
	d.setdefault(b, [])
	d[b].append(c)


d=OrderedDict(sorted(d.items()))

f = True
for k,v in d.items():
	if k >= a[0]:
		f = False
		break
	else:
		for i in v:
			a[0]+=i
if(f == False):
	print("NO")
else:
	print("YES")
