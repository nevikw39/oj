def main():
    s = input()
    t = input()
    
    if tuple(c for c in s if c != 'A') != tuple(c for c in t if c != 'A'):
        print("-1")
        return

    def f(x): return [len(i) for i in "".join(c if c == 'A' else '|' for c in x).split('|')]

    print(sum(abs(a - b) for a, b in zip(f(s), f(t))))

if __name__ == "__main__":
    main()
