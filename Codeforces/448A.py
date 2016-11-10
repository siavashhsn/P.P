a = list(map(int, input().split()))
b = list(map(int, input().split()))
n = input()
aa = sum(a)
bb = sum(b)
nn = int(n)

for i in range(int(n)):
	if aa != 0:
		if aa < 5:
			aa = 0
		else:
			aa -= 5
		nn-=1
	else:
		break

for i in range(int(n)):
	if(bb != 0):
		if bb < 10:
			bb = 0
		else:
			bb -= 10
		nn-=1
	else:
		break

if nn < 0 or bb != 0 or aa != 0:
	print("NO")
else:
	print("YES")


