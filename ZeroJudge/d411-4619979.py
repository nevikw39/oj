import sys
for line in sys.stdin:
    lst = line.split()
    m, n = map(int, lst)
    print('�i�c!!��F�o��[%s���M�L�k�Q2��%s���㰣' % (lst[0], lst[1]) if m % (1 << n) else 'YA!!�ש��X%s�i�Q2��%s���㰣�F!!' % (lst[0], lst[1]))
