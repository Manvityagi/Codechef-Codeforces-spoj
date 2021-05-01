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
bool prime[maxn];
void sieve()
{
    prime[1] = 0, prime[2] = 1;
    for (int i = 3; i * i <= maxn; i++)
    {
        if (!prime[i])
            continue;
        for (int j = i * 2; j <= maxn; j += i)
        {
            prime[j] = 0;
        }
    }
}

bool perfect(int n)
{
    return ceil(sqrt(n)) == floor(sqrt(n));
}
void solve()
{
    int n;
    cin >> n;
    int ans = INT_MAX;

    for (int j = 1; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            ans = min(ans, 2 * (j + n / j));
        }
    }
    cout << ans << "\n";
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

    while (t--)
    {
        solve();
    }
    return 0;
}