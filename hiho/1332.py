import re

class Number(object):
    def __init__(self, v):
        self.x = v

    def __sub__(self, v):
        return Number(self.x - v.x)

    def __add__(self, v):
        return Number(self.x + v.x)

    def __mul__(self, v):
        return Number(self.x * v.x)

    def __div__(self, v):
        return Number(int(1.*self.x/v.x))


    def __neg__(self):
        return Number(-self.x)

    def __pos__(self):
        return Number(self.x)
        

if __name__ == '__main__':
    s = raw_input()
    s = re.sub('([0-9]+)', r'Number(\1)', s)
    print eval(s).x

        