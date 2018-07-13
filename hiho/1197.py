import re

if __name__ == '__main__':
    t = raw_input()
    while t != '':
        s = re.sub(r"\s{2,}", " ", t).replace(' ,', ',').lower()
        flag = True
        ret = ''
        for i in s:
            if flag:
                ret += i.upper()
                flag = False
            else:
                ret += i
            if i == '.':
                flag = True
        print ret
        try:
            t = raw_input()
        except:
            break

