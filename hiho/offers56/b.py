def check(x):
    if len(x) == 0:
        return False
    if x[0] == '.' or x[-1] == '.':
        return False
    if (x != '0' and x[:2] != '0.' and x[0] == '0') or ('.' in x and x[-1] == '0'):
        return False
    return True

def main():
    s = raw_input()
    n = len(s)
    ans = set()
    for i in xrange(1, n):
        for j in xrange(i, n):
            for k in xrange(j, n):
                x = '.'.join([s[:i], s[i:j]])
                y = '.'.join([s[j:k], s[k:]])
                if check(x) and check(y):
                    ans.add(','.join([x, y]))

                x1 = s[:j]
                if check(x1) and check(y):
                    ans.add(','.join([x1, y]))

                y1 = s[j:]
                if check(x) and check(y1):
                    ans.add(','.join([x, y1]))

                if check(x1) and check(y1):
                    ans.add(','.join([x1, y1]))


    for i in sorted(ans, key=lambda x: (float(x.split(',')[0]), float(x.split(',')[1]))):
        print i

if __name__ == '__main__':
    main()