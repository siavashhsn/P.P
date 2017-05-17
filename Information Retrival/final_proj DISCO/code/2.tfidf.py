import glob
import math
import time

start_time = time.time()

extracttw_DIR = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/Extract_tw/"
indexedtw_DIR = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/Indexed_tw/indexed_1.txt"
tfidf_DIR     = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/tfidf/"

# indexfile = glob(indexedtw_DIR)
indexmap = {}
with open(indexedtw_DIR) as f:
	a = f.read()
	b = list(a.split('\n'))
	for k in b:
		c = list(k.split(':'))
		d = list(c[1].split(','))
		d = list(filter(None, d))
		indexmap[c[0]] = d
print(len(indexmap))


counter = 0
cc = 0
extractstr = ""
extractfile = glob.glob(extracttw_DIR + '*')
extractlist = []
for f in extractfile:
	with open(f) as f:
		wordlist = []
		a = f.read()
		w = list(a.split('\n'))			#split each line
		w = list(filter(None, w))
		for b in w:
			wordmap = {}
			counter += 1
			c = list(b.split('='))			#split id & words
			# print(c)
			d = list(c[1].split(','))		#split word from each others
			for i in d:
				 e = list(i.split(':'))
				 wordlist.append(e[0])

			# print(wordlist)
			wordlist = list(filter(None, wordlist))
			 
			for i in wordlist:
				if i not in wordmap:
					tf = wordlist.count(i) #term ferequency
					wtf = 1 + math.log10(tf)
					df = len(indexmap[i])
					idf = math.log10((len(w)/df))
					tfidf = tf * idf
					wordmap[i] = round(tfidf,2)
					# print(tfidf)
			extractstr += c[0] + '='
			for k, v in wordmap.items():
				extractstr += k + ':' + str(v) + ','
			extractstr += '\n'
			wordlist.clear()
			wordmap.clear()
			if(counter == 1000):
				cc+=1
				exfile = open(tfidf_DIR + str(cc) + "tfidf.txt", 'w')
				counter = 0
				exfile.write(extractstr)
				exfile.close()
				extractstr = ""
				wordlist.clear()
				wordmap.clear()
cc+=1
counter = 0
exfile = open(tfidf_DIR + str(cc) + "tfidf.txt", 'w')
exfile.write(extractstr)
exfile.close()
print(time.time() - start_time)

 
