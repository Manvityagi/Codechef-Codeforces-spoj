def main():
    t = int(input())
    while t > 0:
        n, k = map(int, input().split())
        arr = [int(e) for e in input().split()]

        mp = {}
        vec = []
        for i in range(int(n/2)):
            if arr[i] + arr[n-i-1] not in mp:
                mp[arr[i]+arr[n-i-1]] = 0
            mp[arr[i]+arr[n-1-i]] += 1
            vec.append([min(arr[i], arr[n-i-1]), max(arr[i], arr[n-i-1])])

        pre = [0 for i in range(2*k+10)]

        for f, s in vec:
            l = f + 1
            r = s + k
            pre[l] += 1
            pre[r+1] -= 1

        sum = 0
        for i in range(0, 2*k+11):
            sum += pre[i]
            pre[i] = sum

        ans = n
        for x in range(2, 2*k+1):
            cnt0 = mp.get(x)
            if cnt0 == None:
                continue
            cnt1 = pre[x]-cnt0
            cnt2 = n/2-cnt0-cnt1
            ans = min(ans, cnt1+2*cnt2)

        print(ans)
        t -= 1

if __name__ == "__main__":
    main()
