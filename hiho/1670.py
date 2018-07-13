
def diff(date, date1):
    m, d = map(int, date.split('-'))
    m1, d1 = map(int, date1.split('-'))
    if m == m1:
        return d - d1
    if m > m1 + 1:
        return 10
    if m1 == 2:
        return d - d1 + 28
    elif m1 in [1, 3, 5, 7, 8, 10, 12]:
        return d - d1 + 31
    else:
        return d - d1 + 30


def check(x, date, prev):
    date1 = prev[x]
    prev[x] = date
    if date1 == '' or diff(date, date1) > 1:
        return True
    return False


def main():
    n, m = map(int, raw_input().split())
    prev = ['' for i in xrange(n+1)]
    a = []
    for i in xrange(m):
        date, x, y = raw_input().split()
        x, y = map(int, [x, y])
        a.append((date, x, y))

    a = sorted(a)
    for i in xrange(m):
        date, x, y = a[i]
        if not check(x, date, prev) or not check(y, date, prev):
            print 'NO'
            return
    print 'YES'


if __name__ == '__main__':
    T = int(raw_input())
    for i in xrange(T):
        main()