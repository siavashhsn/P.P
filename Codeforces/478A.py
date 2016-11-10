a = [int(i) for i in input().split()]
b = a[0]+a[1]+a[2]+a[3]+a[4]
if(b%5==0):
	if(b/5!=0):
		print(int(b/5))
	else:
		print(-1)
else:
	print(-1)