a, b = map(int, input().split())

c = 10**(a-1)
d = 10**a

t = True
for i in range(c, d):
	if(i%b==0):
		print(i)
		t = False
		break
if(t == True):
	print(-1)