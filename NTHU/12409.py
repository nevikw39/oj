s1 = input('Enter a string:\n')
s2 = input('Enter another string:\n')
if len(s1) == len(s2):
    print("First string: {} (length {})\nSecond string: {} (length {})".format(s1, len(s1), s2, len(s2)))
    exit(0)
if len(s1) > len(s2):
    s1, s2 = s2, s1
print("Shorter string: {} (length {})\nLonger string: {} (length {})".format(s1, len(s1), s2, len(s2)))
