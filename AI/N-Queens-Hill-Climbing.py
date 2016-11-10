import random

def calc_H(l,n):
    h = 0
    # n = len(l)
    for i in range(0, n-1):
        for j in range(i+1, n):
            if l[i] == l[j]:
                h+=1
            elif abs(i-j) == abs(l[i]-l[j]):
                h+=1
    return h

def hill_climbing(l):
    while 1:
        h = calc_H(l , len(l))
        d = []
        d.append((list(l), h))
        q = 1
        y = l
        ll = l
        seen = []
        seen.append(list(l))
        p = len(l)
        while p > 0:
            p-=1
            for i in range(0,len(l)):
                for j in range(1, len(l)+1):
                    if j != i:
                        l[i] = j
                        h = calc_H(l, len(l))
                        d.append((list(l), h))
            # print(d)
            k = min(d, key=lambda x: x[1])
            l = list(k[0])
            d = []
            h = calc_H(l, len(l))
            # print('state ', q, '      : ', l, ': H = ', h)
            q += 1
            ll = l
            d = []
            d.append((list(y), calc_H(y, len(y))))
        if(calc_H(l, len(l)) != 0):
            l = []
            for i in range(n):
                l.append(random.randrange(1, n + 1))
                d.clear()
        else:
            break
    return l

n = int(input("Initialize Number Of Queens : "))
print("\nRandomly initialize the queens...\n")
main_matrix = []
for i in range(n):
    main_matrix.append(random.randrange(1, n+1))
print('Initial matrix : ', main_matrix, ': H = ', calc_H(main_matrix, len(main_matrix)))
l = hill_climbing(main_matrix)
print("final result   : ", l, ": H = ", calc_H(l, len(l)))