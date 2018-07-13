#coding=utf8

if __name__ == '__main__':
    n = int(raw_input())
    s = set()
    for i in xrange(n):
        m = int(raw_input())
        t = set()
        for j in xrange(m):
            x, _, y = raw_input().split()[:3]
            t.add((x, float(y)))
        if i == 0:
            s = t
        else:
            s &= t
    for i in sorted(s):
        print i[0]



'''
Problem >_{
    给n个列表，每个列表里有若干个(商品号，时间，价格)，(商品号，价格)唯一确定一个商品，求哪些商品在所有列表都出现过。递增顺序输出商品号，如果一个商品号对应多个价格，输出多次。
}_<

Solution >_{
   python暴力 
}_<
'''