for _ in range(int(input())):
    a, b = input().split()
    print(str(int(a[::-1]) + int(b[::-1])).rstrip('0')[::-1])