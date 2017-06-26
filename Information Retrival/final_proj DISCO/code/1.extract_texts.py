from nltk.stem.porter import *
from string import digits
import pymysql
import glob
import time

start_time = time.time()


extract_tw = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/Extract_tw/"
indexed_tw = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/Indexed_tw/"
main_tw = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/Main_tw/"
main_tw_ = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/Main_tw/*"
indexed_tw_ = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Projects/final_proj/Extract_twitts/Indexed_tw/*"



path = "/media/siavash/000AF8440AF837EC/cources/Information_Retrival/Proj/Datasets/Tweeters_dataset/Test(300)/*"

tweet = {}
st = "*** < > / \\ ] [ } { \' \" : ; , . == ** = + ) ( * & ^ % $ # @ ! - _ ... a [pic] b c d e f g h i j k l m n o p q r s t u v w x y z about above after again against all am an and any are aren't as at be because been before being below between both but by can't cannot could couldn't did didn't do does doesn't doing don't down during each few for from further had hadn't has hasn't have haven't having he he'd he'll he's her here here's hers herself him himself his how how's i i'd i'll i'm i've if in into is isn't it it's its itself let's me more most mustn't my myself no nor not of off on once only or other ought our ours ourselves out over own same shan't she she'd she'll she's should shouldn't so some such than that that's the their theirs them themselves then there there's these they they'd they'll they're they've this those through to too under until up very was wasn't we we'd we'll we're we've were weren't what what's when when's where where's which while who who's whom why why's with won't would wouldn't you you'd you'll you're you've your yours yourself yourselves"
stop = list(st.split(' '))
stop.append('')
stop.append(' ')
s = ['*', '<', '>', '/', '\\', ']', '[', '}', '{', '\'', '"', '“', '”', '’', '‘', '•', ':', ';', ',', '.', '·', '=', '+', ')', '|', '(', '*',
     '&', '^', '%', '$','#', '@', '!', '?', '-', '_', '.', '~', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '►', '♥', '▸']
ss = ['*', '<', '>', '/', '\\', ']', '[', '}', '{', '\'', '"', '“', '”', '’', '‘', '•', ':', ';', ',', '.', '·', '=', '+', ')', '|', '(', '*',
     '&', '^', '%', '$','#', '@', '!', '?', '-', '_', '.', '~']


t_count = 0
www = 1



def wtof(w_path):  # write to file function
    word = {}
    s = ""
    o = open(w_path + str(www) + '.txt' , 'w')
    for k, v in tweet.items():
        for i in v:
            if i in word:
                word[i].append(k)
            else:
                aa = []
                aa.append(k)
                word[i] = list(aa)
    maint = ""
    for k, v in word.items():
        maint += k + ":"
        for t in v:
            maint += t + ","
        maint += "\n"
    o.write(maint)
    tweet.clear()
    word.clear()



def readfromf_writetof():  # read all outputs and write it to one file
    word = {}
    files = glob.glob(indexed_tw_)
    q = 2
    w = 1
    for name in files:
        with open(name) as f:
            output = f.read()
            output = output[:-1]
            opl = list(output.split("\n"))
            for i in opl:
                k = list(i.split(':'))
                if k[0] in word:
                    sss = list(word[k[0]].split(','))
                    ss = list(k[1].split(','))
                    s = ""
                    for iii in sss:
                        if iii not in ss:
                            ss.append(iii)
                    for iii in ss:
                        s += iii + ','
                    s = s[:-1]
                    word[k[0]] = s
                else:
                    if len(k) >= 2:
                       word[k[0]] = k[1]
    o = open(indexed_tw + "indexed_" + str(w) + ".txt", 'w')
    # w += 1
    # q -= 1
    # if q == 0:
        # q = 2
    maint = ""
    for k, v in word.items():
        maint += k + ":" + v + "\n"
    maint = maint[:-1]
    o.write(maint)
    word.clear()
    o.close()
    # if q != 2:
    #     o = open("indexed_" + str(w) + ".txt", 'w')
    #     w += 1
    #     maint = ""
    #     for k, v in word.items():
    #         maint += k + ":" + v + "\n"
    #     maint = maint[:-1]
    #     o.write(maint)
    #     word.clear()



files = glob.glob(path)
tt = ""
ttt = ""
extracttw = ''
maint = ""
mt = ""
txt = ""
jj=""
for f in files:
    t_count += 1
    with open(f) as f:
        text = f.read()
        textl = list(text.split("\n"))
        for j in textl:
            try:
                if "Text:" in j:
                    i = j.lower()
                    d = i.replace('text: ', '')
                    mt = d;
                    for t in s:
                        e = d.replace(t, '')
                        d = e
                    TXT = list(d.split(' '))
                    for t in TXT:
                        if t == ' ':
                            TXT.remove(t)
                        else:
                            we = t.replace(' ', '')
                            t = we
                    ll = [w for w in TXT if w not in stop]
                    # porter = PorterStemmer()
                    # # if len(ll):
                    #     # print(ll)
                    # jj = [porter.stem(p) for p in ll]   
                    
                if "ID:" in j:
                    ID = list(j.split(' '))
                    ID.remove(ID[0])
                    for qw in ss:
                        f = mt.replace(qw, '')
                        mt = f
                    tweet[ID[0]] = list(jj)
                    maint += ID[0] + '=' + mt + '\n'
                    extracttw += ID[0] + '=' + ':,'.join(jj)+':\n'
                    jj = ""
                    mt = ""
            except IndexError:
                aaa = ""

        if t_count == 100:

            # #######extract_tw#######
            extr = open(extract_tw + str(www) + ".txt", 'w')
            extr.write(extracttw)
            extracttw = ""
            txt = ""
            ttt = ""
            extr.close()
            # #######main_tw#######
            mainttw = open(main_tw + str(www) + ".txt", 'w')
            mainttw.write(maint)
            maint = ""

            # #######indexed_tw#######
            wtof(indexed_tw)
            print(www * 100)
            print("--- %s seconds ---" % (int(time.time() - start_time)))

            t_count = 0
            www += 1
            # allt = open(indexed_tw + str(w-100) + ".txt", 'w')
            # allt.write(extracttw)
            # allt.close()

readfromf_writetof()
