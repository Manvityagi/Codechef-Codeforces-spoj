def fact(num):
    factorial = 1
    if num == 0:
        return 1
    else:
        for i in range(1, num + 1):
            factorial = factorial * i
        return factorial


def ncr(n, r):
    return (fact(n)) // (fact(r) * (fact(n - r)))


n = int(input())
k = n // 2
ans = ncr(n, n // 2) // 2 * fact(k) // k * fact(k) // k
print(ans)
