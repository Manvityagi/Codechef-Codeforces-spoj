import math

t = int(input())
while t > 0:
    try:
        n = int(input())
        l = input()
        a = list(map(int, l.split(" ")))
        left = a.copy()
        right = a.copy()
        for i in range(1, n):
            left[i] = left[i] * left[i - 1]
        for i in range(n - 2, -1, -1):
            right[i] = right[i] * right[i + 1]
        ans = -1
        for i in range(0, n - 1):
            part1 = left[i]
            part2 = right[i + 1]
            if math.gcd(part1, part2) == 1:
                ans = i + 1
                break
    except EOFError as e:
        print("hello")
    t = t - 1

    print(ans)

