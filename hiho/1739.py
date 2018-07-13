def main():
    n = int(raw_input())
    n -= 1
    a = []
    ans = 0
    for i in xrange(n):
        x, y, z, w = map(int, raw_input().split())
        w = x ^ y ^ w
        a.append((w, z))
        ans += w

    a = sorted(a, key=lambda x: -x[0])

    if len(filter(lambda x: x[1] != 1, a)) == 0:
        print "No"
        return

    s = [0] * 60
    for w, x in a:
        if x != 1:
            for i, j in enumerate(s):
                if (x >> i) & 1:
                    x ^= j
            if x != 0:
                ans -= w
                for i, j in enumerate(s):
                    if ((x >> i) & 1) and j == 0:
                        s[i] = x
                        break

    print ans






if __name__ == '__main__':
    main()
