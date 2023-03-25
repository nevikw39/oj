s = {"and", "not", "that", "the", "you"}
n = int(input())
for i in input().split():
    if i in s:
        print("Yes")
        break
else:
    print("No")
