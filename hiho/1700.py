


def main():
    s = raw_input()


    x, y, z = eval('0x' + s[1:3]), eval('0x' + s[3:5]), eval('0x' + s[5:])
    mn = 10000000000000
    ans = -1
    for i in xrange(0, 0x10):
        for j in xrange(0, 0x10):
            for k in xrange(0, 0x10):
                dist = (x - i*16-i)**2 + (y - j*16-j)**2 + (z - k*16-k)**2
                if dist < mn:
                    mn = dist
                    ans = '#%s%s%s' % (hex(i)[2:], hex(j)[2:], hex(k)[2:])

    print ans


if __name__ == '__main__':
    main()


'''
Problem >_{
    #40e0d0表示一种颜色，每两个一组，如果两位相同可以简化成一位，例如#639与#663399相同
    定义两个颜色#abcdef和#ghijkl的距离$(ab - gh)^2 + (cd - ij)^2 + (ef - kl)^2$
    给一个六位颜色，求与它距离最近的3位颜色
}_<

Solution >_{
    枚举
}_<
'''