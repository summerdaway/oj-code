def calc(p, l, s):
    cur = 0
    ans = ['']
    for i, j in enumerate(s):
        if i:
            if cur + 1 + len('(%s/' % len(ans) + 'x'*p + ')') > l:
                ans[-1] += '(%s/' % len(ans) + '{}' + ')'
                ans.append('')
                cur = 0
            ans[-1] += ' '
            cur += 1
        if cur + len(j) + len('(%s/' % len(ans) + 'x'*p + ')') > l:
            ans[-1] += '(%s/' % len(ans) + '{}' + ')'
            ans.append('')
            cur = 0
        ans[-1] += j
        cur += len(j)
    ans[-1] += '(%s/' % len(ans) + '{}' + ')'


    if len(str(len(ans))) == p:
        for i, j in enumerate(ans):
            print j.format(len(ans))
        return True
    return False

def main():
    l = int(raw_input())
    s = raw_input().split(' ')
    for i in xrange(1, 6):
        if calc(i, l, s):
            break

if __name__ == '__main__':
    main()