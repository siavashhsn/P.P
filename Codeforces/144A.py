a = int(input())
mi = 100000000
ma = -100000000
mii = 0
mai = 0

b = [int(i) for i in input().split()]

for i in range(a):
	c = b[i]
	if(mi>=c):
		mi=c
		mii=i
	if(ma<c):
		ma=c
		mai=i

if(mii<mai):
	print(a-(mii+1)+mai-1)
else:
	print(a-(mii+1)+mai)
