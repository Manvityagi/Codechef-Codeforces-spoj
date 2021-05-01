
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define ULL unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
#define int LL
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> arr(n), bits(61); //ith bit is active in how many numbers
    for (auto &i : arr)
        cin >> i;
    for (auto ele : arr)
    {
        for (int i = 0; i <= 60; i++)
        {
            if ((ele >> i) & 1)
                bits[i]++;
        }
    }

    for (auto ele : arr)
    {
        int and_val = 0, or_val = 0;
        for (int i = 0; i <= 60; i++)
        {
            int temp = (1ll << i); //contribution of ith bit
            temp %= MOD1;

            //and val will exist only if ith bit of ele is set
            if ((ele >> i) & 1)
            {
                int add = (bits[i] % MOD1 * temp % MOD1) % MOD1; //total contribution from all the numbers
                and_val = (and_val % MOD1 + add % MOD1) % MOD1;
            }

            //OR_VAL, IF ele ith bit is 1, all the numbers will contribute to the sum , else bits[i]
            int cont = (ele >> i) & 1 ? n : bits[i];
            int add = (cont % MOD1 * temp % MOD1) % MOD1;
            or_val = (or_val % MOD1 + add % MOD1) % MOD1;
        }

        ans = (ans % MOD1 + (and_val % MOD1 * or_val % MOD1) % MOD1) % MOD1;
    }

    cout << ans % MOD1 << "\n";
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}