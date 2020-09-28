#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define pii pair<int, int>

LL expo(LL x, LL n)
{
    if (x == 1 || n == 0)
        return 1;
    if (n == 1)
        return x;

    LL ans = expo(x, n / 2);
    ans *= ans;

    if (n & 1)
        ans *= x;

    return x;
}
vector<int> factors(int x)
{
    int lmt = sqrt(x);
    vector<int> f;
    if (x % 2 == 0)
    {
        while (x % 2 == 0)
            x /= 2;
        f.push_back(2);
    }

    for (int i = 3; i <= lmt; i += 2)
    {
        if (x % i == 0)
        {
            while (x % i == 0)
                x /= i;
            f.push_back(i);
        }
    }

    if (x > 2)
        f.push_back(x);
    return f;
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    // cin >> t;
    map<pii, int> mp;
    while (t--)
    {
        LL n;
        cin >> n;
        vector<int> arr(n);
        for (auto &i : arr)
        {
            cin >> i;
            vector<int> fact = factors(i);
            for (auto j : fact)
            {
                int cnt = 1;
                while (i % j == 0)
                {
                    mp[MP(j, cnt)]++;
                    i /= j;
                    cnt++;
                }
                mp[MP(j, 0)]++;
            }
        }

        map<int, int> power;
        for (auto i : mp)
        {
            if (i.S >= n - 1)
                power[i.F.F] = max(power[i.F.F], i.F.S);
        }

        LL ans = 1;
        for (auto i : power)
            ans *= expo(i.F, i.S);

        cout << ans << "\n";
    }
    return 0;
}
