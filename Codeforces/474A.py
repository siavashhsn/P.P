a = input()
b = input()
c = "qwertyuiopasdfghjkl;zxcvbnm,./"
d = ""

for i in range(len(b)):
	if a=='L':
		d+=c[c.index(b[i])+1]
	else:
		d+=c[c.index(b[i])-1]
print(d)