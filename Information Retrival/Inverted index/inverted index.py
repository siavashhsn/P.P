import glob
import pymysql
from nltk.stem.porter import *
from string import digits

path = '/media/siavash/000AF8440AF837EC/web/tweets/*'
# path = "/home/siavash/Desktop/courcess/web/Test/*"
wpath = '/home/siavash/Desktop/courcess/web/Outputs/'
woutput = '/home/siavash/Desktop/courcess/web/final_output/'
rpath = '/home/siavash/Desktop/courcess/web/Outputs/*'

tweet = {}
st = "*** < > / \\ ] [ } { \' \" : ; , . == ** = + ) ( * & ^ % $ # @ ! - _ ... a [pic] b c d e f g h i j k l m n o p q r s t u v w x y z about above after again against all am an and any are aren't as at be because been before being below between both but by can't cannot could couldn't did didn't do does doesn't doing don't down during each few for from further had hadn't has hasn't have haven't having he he'd he'll he's her here here's hers herself him himself his how how's i i'd i'll i'm i've if in into is isn't it it's its itself let's me more most mustn't my myself no nor not of off on once only or other ought our ours ourselves out over own same shan't she she'd she'll she's should shouldn't so some such than that that's the their theirs them themselves then there there's these they they'd they'll they're they've this those through to too under until up very was wasn't we we'd we'll we're we've were weren't what what's when when's where where's which while who who's whom why why's with won't would wouldn't you you'd you'll you're you've your yours yourself yourselves"
stop = list(st.split(' '))
stop.append('')
stop.append(' ')
s = ['*', '<', '>', '/', '\\', ']', '[', '}', '{', '\'', '"', '“', '”', '’', '‘', '•', ':', ';', ',', '.', '·', '=', '+', ')', '|', '(', '*',
     '&', '^', '%', '$','#', '@', '!', '?', '-', '_', '.', '~', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
ss = ['*', '<', '>', '/', '\\', ']', '[', '}', '{', '\'', '"', '“', '”', '’', '‘', '•', ':', ';', ',', '.', '·', '=', '+', ')', '|', '(', '*',
     '&', '^', '%', '$','#', '@', '!', '?', '-', '_', '.', '~']


try:
    conn = pymysql.connect(host='localhost', user='inverted_index', passwd='root', db='inverted_index', autocommit=True)
except():
    print("Oops.. failed to connect")


cur = conn.cursor()


def do_insert_query(v1 , v2):
    try:
        if len(v1) and len(v2):
            cur = conn.cursor()
            cur.execute("INSERT INTO indexed_words (ID ,word, tweets) VALUES (NULL,'"+v1+"', '"+v2+"');")
    except:
        print("Oops..! failed to insert in db!!")


def do_select_indexed(word):
    l=""
    try:
        cur.execute("SELECT * FROM indexed_words WHERE word = '"+word+"'")
        for id, w, t in cur.fetchall():
            if t[len(t)-1] == ',':
                l += t
            else:
                l += ',' + t

        return l
    except:
        print("failed to select from db")


def do_select_tweets(tid):
    l={}
    try:
        cur.execute("SELECT * FROM tweets WHERE TID = '"+tid+"'")
        for id, ttid, t in cur.fetchall():
            l[ttid] = t
        return l
    except:
        print("failed to select from db")


def insert_tweets(v1, v2):
    try:
        cur.execute("INSERT INTO tweets VALUES (NULL, '" + v1 + "','" + v2 + "');")
        # print("tweet inserted")
    except:
        print("failed to insert to tweets")


def wtof(w_path):  # write to file function
    word = {}
    s = ""
    o = open(w_path, 'w')
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


idtext = {}


def insertidtext():
    # qq = 1
    for k, v in idtext.items():
        insert_tweets(k, v)
        # print(qq)
        # qq += 1
    idtext.clear()


def read_tokenize_normalize_write():  # playing with files and do changes and save it as a text in wpath
    q = 20
    w = 1
    files = glob.glob(path)
    tt = ""
    ttt = ""
    for name in files:
        if w != 6:
            with open(name) as f:
                text = f.read()
                textl = list(text.split("\n"))
                txt = []
                for j in textl:
                    i = j.lower()
                    ID = []
                    if "text: " in i:
                        d = i.replace('text: ', ' ')
                        tt = d
                        for t in s:
                            f = d.replace(t, '')
                            d = f
                        i = d
                        TXT = list(i.split(' '))
                        for t in TXT:
                            if t == ' ':
                                TXT.remove(t)
                            else:
                                we = t.replace(' ', '')
                                t = we
                        ll = [w for w in TXT if w not in stop]
                        # print(ll)
                        porter = PorterStemmer()
                        j = [porter.stem(p) for p in ll]
                        txt.clear()
                        txt = j
                    if "id: " in i:
                        ID = list(i.split(' '))
                        ID.remove(ID[0])
                        for qw in ss:
                            f = tt.replace(qw, '')
                            tt = f
                        ttt += ID[0] + "***:::***" + tt + "\n"
                        idtext[ID[0]] = tt
                        tweet[ID[0]] = list(txt)
                        txt.clear()
                q -= 1
                print(str(w) + " : " + str(q))
                if q == 0:   # write to file each 4000 files once
                    q = 20
                    o = open("/home/siavash/Desktop/courcess/web/ID_texts/ID_TEXT_" + str(w) + ".txt", 'w')
                    insertidtext()
                    idtext.clear()
                    o.write(ttt)
                    ttt = ""
                    wtof(wpath+"output-"+str(w)+".txt")
                    w += 1
                    tweet.clear()


def readfromf_writetof():  # read all outputs and write it to one file
    word = {}
    files = glob.glob(rpath)
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
                    word[k[0]] = k[1]
            o = open(woutput + "final_output_" + str(w) + ".txt", 'w')
            w += 1
            q -= 1
            if q == 0:
                q = 2
                maint = ""
                for k, v in word.items():
                    maint += k + ":" + v + "\n"
                maint = maint[:-1]
                o.write(maint)
                for k, v in word.items():
                    do_insert_query(k, v)
                word.clear()
    if q != 2:
        o = open(woutput + "final_output_" + str(w) + ".txt", 'w')
        w += 1
        maint = ""
        for k, v in word.items():
            maint += k + ":" + v + "\n"
        maint = maint[:-1]
        o.write(maint)
        for k, v in word.items():
            do_insert_query(k, v)
        word.clear()




    word.clear()

#
# read_tokenize_normalize_write()
#
# readfromf_writetof()

# put_outputs_in_db()


inp = input("enter the query: ")
inp = inp.lower()
inpl = list(inp.split(' '))

if inpl[0] in s or inpl[2] in s or inpl[0] in stop or inpl[2] in stop:
    print("query is wronge !!")

for t in s:
    f1 = inpl[0].replace(t, '')
    f2 = inpl[2].replace(t, '')
    inpl[0] = f1
    inpl[2] = f2


print(inpl)

porter = PorterStemmer()
x1 = porter.stem(inpl[0])
x2 = porter.stem(inpl[2])

inpl[0] = x1
inpl[2] = x2
print(inpl)
print("\n")

w1 = do_select_indexed(inpl[0])
w2 = do_select_indexed(inpl[2])


wl1 = {}
wl2 = {}



if len(w1) > 0 and len(w2) > 0:
    ww = w1.replace(' ', '')
    www = ww[:-1]
    w1 = www
    l1 = list(w1.split(','))

    ww = w2.replace(' ', '')
    www = ww[:-1]
    w2 = www
    l2 = list(w2.split(','))

    print("\n")

    out = []

    if inpl[1] == 'and':
        out = set(l1) & set(l2)
        print(out)
    elif inpl[1] == 'or':
        out = set(l1) | set(l2)
        print(out)
    elif inpl[1] == 'not':
        out = set(l1) & set(l2)
        out1 = [item for item in l1 if item not in l2]
        out2 = [item for item in out1 if item not in out]
        out  = out2
        print(out)

    outl = {}
    for i in out:
        outl = do_select_tweets(i)
        for k, v in outl.items():
            print(k+ " : " + v)
else:
    if len(w1) == 0:
        print(inpl[0]+" : invalid word")
    if len(w2) == 0:
        print(inpl[2] + " : invalid word")

conn.close()