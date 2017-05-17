from collections import OrderedDict
from scipy import spatial
import numpy as np
import operator
import glob
import math
import heapq
np.seterr(divide='ignore', invalid='ignore')


import time

start_time = time.time()



tfidf_DIR = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/tfidf/*"
cosine_DIR = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/tfidf_cosine/"


tfidf_file = glob.glob(tfidf_DIR)

maxcos = 0.70
resultmap={}
cosstr = ""

counter1 = 0
counter2 = 0



for f in tfidf_file :
	with open(f) as f:
		a = f.read()
		c = []
		firstmap = {}
		firstlist = []
		secondmap = {}
		secondlist = []

		pickedtw = []

		b = list(a.split('\n'))
		for i in b:						#baraye twitte aval ke mikhayhim 5 ta shabih ra peyda konim barayash
			c = list(i.split('='))			#
			wordlist = []
			if len(c) == 2:						#
				d = list(c[1].split(','))			#
				d = list(filter(None, d))				#
				for j in d:									#
					e = list(j.split(':'))						#
					# print(e)										#
					firstmap[e[0]] = float(e[1])						#
					if e[0] not in wordlist:								#
						wordlist.append(e[0])									#

				for ff in tfidf_file:
					with open(ff) as ff:
						
						aa = ff.read()
						cc = []
						bb = list(aa.split('\n'))
						for ii in bb:						#
							wordlist2 = list(wordlist)
							cc = list(ii.split('='))			#
							if cc[0] != c[0]:						#
								if len(cc) == 2:						#
									dd = list(cc[1].split(','))				#
									dd = list(filter(None, dd))					#
									for jj in dd:									#
										ee = list(jj.split(':'))						#
										secondmap[ee[0]] = float(ee[1])						#
										if ee[0] not in wordlist2:								#
											wordlist2.append(ee[0])									#

									for w in wordlist2:
										if w in firstmap:
											firstlist.append(float(firstmap[w]))
										else:
											firstlist.append(0)
										if w in secondmap:
											secondlist.append(float(secondmap[w]))
										else:
											secondlist.append(0)

									# print('1 : ',firstlist)
									# print('2 : ',secondlist)
									if sum(secondlist) != 0:
										r = 1 - spatial.distance.cosine(firstlist, secondlist)
									else:
										r = 0
									resultmap[cc[0]] = round(r,2)
									counter2 += 1
									
									if counter2 == 100:
										counter2 = 0
										ddd = heapq.nlargest(5, resultmap, key=resultmap.get)
										qqq = {}
										for iii in ddd:
											qqq[iii] = resultmap[iii]
										resultmap.clear()
										resultmap = dict(qqq)

									secondmap.clear()
									secondlist = []
									firstlist = []
				ddd = heapq.nlargest(5, resultmap, key=resultmap.get)
				qqq = {}
				for iii in ddd:
					qqq[iii] = resultmap[iii]
				resultmap.clear()
				resultmap = dict(qqq)
				# print(resultmap)
				counter1+=1
				str1 = str(resultmap)
				cosstr += str(c[0]) + '=' + str1 + '\n'
				resultmap.clear()

				if counter1 % 100 == 0:
					tfcos = open(cosine_DIR + str(counter1) + ".txt", 'w')
					tfcos.write(cosstr)
					tfcos.close()
					cosstr = ""
					print(time.time() - start_time)



				firstmap.clear()
tfcos = open(cosine_DIR + str(counter1) + ".txt", 'w')
tfcos.write(cosstr)
tfcos.close()
