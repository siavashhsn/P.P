from collections import OrderedDict
from scipy import spatial
import numpy as np
import operator
import glob
import math
import os
import commands


a = "1"
b = "2"

tfidf_path = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/code/1.0tfidf.txt"
l = []
ll = []
aaa = 0

with open(tfidf_path) as f:	
	c = f.read()
	d = list(c.split("\n"))
	l.append(d[0])
	l.append(d[1])


# 	c = f.read()
# 	# print(c)
# 	d = list(c.split('\n'))
# 	for i in d:
# 		e = list(i.split('='))
# 		if(str(a) == str(e[0])) and (str(a) not in ll):
# 			l.append(i)
# 			ll.append(e[0])
# 		elif(str(b) == str(e[0])) and (str(b) not in ll):
# 			l.append(i)
# 			ll.append(e[0])
# 		if len(l) == 2:
# 			break

print(l)

firstmap = {}
firstlist = []
secondmap = {}
secondlist = []

ffff = []
ssss = []

wordlist = []

c = list(l[0].split('='))
if len(c) == 2:	
	d = list(c[1].split(','))
	d = list(filter(None, d))
	for j in d:
		e = list(j.split(':'))
		firstmap[e[0]] = float(e[1])
		if e[0] not in wordlist:
			wordlist.append(e[0])
	cc = list(l[1].split('='))
	dd = list(cc[1].split(','))
	dd = list(filter(None, dd))

	for jj in dd:
		ee = list(jj.split(':'))
		secondmap[ee[0]] = float(ee[1])
		if ee[0] not in wordlist:
			wordlist.append(ee[0])
	print(secondmap)

	for w in wordlist:
		if w in firstmap:
			firstlist.append(float(firstmap[w]))
		else:
			firstlist.append(0)
		if w in secondmap:
			secondlist.append(float(secondmap[w]))
		else:
			secondlist.append(0)

	print(firstlist)
	print(secondlist)
	if sum(secondlist) != 0:
		r = 1 - spatial.distance.cosine(firstlist, secondlist)
	else:
		r = 0

print("tfidf cosine similarity is : " + str(r))


avg = 0
count = 0
firstlist = []
secondlist = []

for w in wordlist:
	if w in firstmap:
		firstlist.append(float(firstmap[w]))
	else:
		for ww in wordlist:
			if w in secondmap:
				s = str("java -jar disco-2.0.jar enwiki-20130403-word2vec-lm-mwl-lc-sim/enwiki-20130403-word2vec-lm-mwl-lc-sim/ -s2 " + w + " " + ww)
				(aaaa, bbbb) = commands.getstatusoutput(s)				# bb = float(bbbb)
				avg += float(bbbb)
				count += 1
		firstlist.append(float(avg/count))
		avg = 0
		count = 0
			

	count = 0
	avg = 0
	if w in secondmap:
		secondlist.append(float(secondmap[w]))
	else:
		for ww in wordlist:
			if w in firstmap:
				s = str("java -jar disco-2.0.jar enwiki-20130403-word2vec-lm-mwl-lc-sim/enwiki-20130403-word2vec-lm-mwl-lc-sim/ -s2 " + w + " " + ww)
				(aaaa, bbbb) = commands.getstatusoutput(s)
				count += 1
				avg+=float(bbbb)
		secondlist.append(float(avg/count))
		count = 0
		avg = 0

if sum(secondlist) != 0:
	r = 1 - spatial.distance.cosine(firstlist, secondlist)
else:
	r = 0


print("disco cosine is : " + str(r))


# (aaaa, bbbb) = commands.getstatusoutput("java -jar disco-2.0.jar enwiki-20130403-word2vec-lm-mwl-lc-sim/enwiki-20130403-word2vec-lm-mwl-lc-sim/ -bn football 5")
# print(str(aaaa) + "dfughisudhsidugfsdfygsdfsdf" + str(bbbb))

# 84270226606264321
# 78889186593222656
