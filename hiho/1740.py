
def main():
    s1 = raw_input()
    s2 = raw_input()
    n = len(s2)
    pos = {}
    for i, j in enumerate(s1):
        if j not in pos:
            pos[j] = i
        else:
            if s2[pos[j]] != s2[i]:
                return False
    return True



if __name__ == '__main__':
    T = int(raw_input())
    while T:
        if main():
            print 'YES'
        else:
            print 'NO'
        T -= 1