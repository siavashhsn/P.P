d = {'Q':9, 'q':9, 'R':5, 'r':5, 'B':3, 'b':3, 'N':3, 'n':3, 'P':1, 'p':1, 'K':0, 'k':0}
wi=0
bl=0
for i in range(8):
	a = input()
	for j in range(len(a)):
		if(a[j]!='.'):
			if a[j]<='Z':
				wi+=d[a[j]]
			else:
				bl+=d[a[j]]
if wi > bl:
	print("White")
elif bl > wi:
	print("Black")
else:
	print("Draw")