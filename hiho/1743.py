
MOD = 1000000007

def fast_mod(a, b, x, m):
    if x == 0:
        for i in xrange(m):
            b[i][i] = 1
        return
    fast_mod(a, b, x >> 1, m)
    c = [[0 for i in xrange(m)] for j in xrange(m)]
    for i in xrange(m):
        for j in xrange(m):
            for k in xrange(m):
                c[i][j] += b[i][k] * b[k][j] % MOD
                c[i][j] %= MOD
    if x & 1:
        for i in xrange(m):
            for j in xrange(m):
                b[i][j] = c[i][j]
                c[i][j] = 0
        for i in xrange(m):
            for j in xrange(m):
                for k in xrange(m):
                    c[i][j] += b[i][k] * a[k][j] % MOD
                    c[i][j] %= MOD

    for i in xrange(m):
        for j in xrange(m):
            b[i][j] = c[i][j]

    return


def main():
    n, K = map(int, raw_input().split())
    if K == 1:
        X = [1, 1]
        f = [1, 1]
    elif K == 2:
        X = [2,0,2,0,-1]
        f = [1, 1, 2, 6, 14][::-1]
    else:
        X = [2, 2, 0, 10, 8, -2, -16, -10, -2, 4, 2, 0, 2, 1]   
        f = [1, 1, 2, 6, 24, 78, 230, 675, 2069, 6404, 19708, 60216, 183988, 563172][::-1]

    m = len(X)
    a = [[0 for i in xrange(m)] for j in xrange(m)]
    for i, j in enumerate(X):
        a[i][0] = j
    for i in xrange(m-1):
        a[i][i+1] = 1

    if n < len(X):
        print f[len(X)-n-1]
        return

    b = [[0 for i in xrange(m)] for j in xrange(m)]
    fast_mod(a, b, n-len(X)+1, m)

    ans = 0
    for i in xrange(m):
        ans += f[i] * b[i][0] % MOD
        ans %= MOD
    print ans



if __name__ == '__main__':
    main()