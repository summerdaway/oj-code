
def foo(x, t):
    flag = False
    ret = 0
    while len(t):
        x += 1
        if not t.startswith(str(x)):
            if flag:
                return -1
            else:
                flag = True
                ret = x
        else:
            t = t[len(str(x)):]

    if ret == 0:
        ret = x + 1
    return ret


if __name__ == '__main__':
    s = raw_input()

    tmp = foo(int(s[0]), s[1:])
    if tmp != -1:
        print tmp
    else:
        print foo(int(s[:2]), s[2:])


    