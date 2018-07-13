if __name__ == '__main__':
    n = int(raw_input())
    s = []
    t = set()
    for i in xrange(n):
        s.append(raw_input())
        for j in s[-1]:
            if 'A' <= j <= 'Z':
                t.add(j)
    m = len(t)
    q = int(raw_input())
    for i in xrange(q):
        f = {}
        for j in xrange(m):
            f.update(dict([raw_input().split()]))
        ret = True
        for j in s:
            p = j
            for k in f:
                p = p.replace(k, f[k])
            ret &= eval(p)
        print (ret and 'Yes') or 'No'


'''
Problem >_{
    给n个包含变量、数字、< 和 <= 的表达式，变量是 A 到 Z，接下来有 q 个查询，每个查询给出每个变量的取值，求是否所有表达式在这组取值下都可以满足
}_<

Solution >_{
    python eval……
}_<
'''