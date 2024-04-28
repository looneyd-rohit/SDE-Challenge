# https://codeforces.com/contest/1954/problem/A

import math

def main():
    test = int(input())
    for _ in range(test):
        n, m, k = map(int, input().split())
        if m <=2:
            if m == 1:
                print("NO")
            elif m == 2:
                if k < (n // 2):
                    print("YES")
                else:
                    print("NO")
        else:
            l = math.ceil(n / m)
            if k >= (n-l):
                print("NO")
            else:
                print("YES")

if __name__ == "__main__":
    main()