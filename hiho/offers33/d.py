
def main():
    n, st = raw_input().split()
    n = int(n)
    s = raw_input().split()

    f = {}
    for i, j in enumerate(s):
        f[j] = i

    ap = [chr(i) for i in xrange(97, 97 + 26)]

    g = {}
    for (idx, i) in enumerate(s):
        if hash(i) not in g:
            g[hash(i)] = {}
        g[hash(i)][i] = idx

    e = [[] for i in xrange(len(s))]
    for (idx, i) in enumerate(s):
        l = len(i)
        for j in ap:
            for k in xrange(l + 1):
                ii = i[:k] + j + i[k:]
                h = hash(ii)
                if h in g and ii in g[h]:
                    e[idx].append(g[h][ii])


    head = 0
    q = []
    if st not in f:
        print 0
        return
    q.append(f[st])
    v = [False for i in xrange(len(s))]
    v[f[st]] = True

    ans = 0
    while head < len(q):
        now = q[head]
        head += 1
        ans = max(ans, len(s[now]))
        for i in e[now]:
            if not v[i]:
                v[i] = True
                q.append(i)

    print ans


    
if __name__ == '__main__':
    main()


