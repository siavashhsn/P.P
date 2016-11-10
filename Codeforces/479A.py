a = int(input())
b = int(input())
c = int(input())

d = -10000000

if a+b+c > d:
	d = a+b+c
if (a+b)*c>d:
	d = (a+b)*c
if a+b*c > d:
	d = a+b*c
if a*b*c > d:
	d = a*b*c
if a*b+c > d:
	d = a*b+c
if a*(b+c)>d:
	d = a*(b+c)
print(d)