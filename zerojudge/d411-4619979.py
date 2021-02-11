import sys
for line in sys.stdin:
    lst = line.split()
    m, n = map(int, lst)
    print('可惡!!算了這麼久%s竟然無法被2的%s次整除' % (lst[0], lst[1]) if m % (1 << n) else 'YA!!終於算出%s可被2的%s次整除了!!' % (lst[0], lst[1]))
