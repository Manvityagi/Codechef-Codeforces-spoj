def check(n,area,h):
    n = (2 * n + 1) / 2
    if (h * n >= area):
        return 1
    return 0

def main():
    t = 1
    while t > 0:
        n, k = map(int, input().split())
        
        lo = 0
        hi = 1e18
        ans = 1e18

        while lo <= hi: 
            mid = lo + (hi - lo) / 2
            if (check(n, k, mid)):
                ans = min(ans, mid)
                hi = mid - 1
            else:
                lo = mid + 1

        print(int(ans))
        t -= 1
 
if __name__ == "__main__":
    main()