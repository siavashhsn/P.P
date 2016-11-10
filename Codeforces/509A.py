a = input()

b = list()

c = int(a)
for i in range(c):
	b.append(1)	
for i in range(c-1):
	for j in range(1, c):
		b[j]=b[j] + b[j-1]

print(b[c-1])