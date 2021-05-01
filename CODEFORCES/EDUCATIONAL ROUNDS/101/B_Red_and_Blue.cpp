
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
    int n, m;
    cin >> n;
    vector<int> r(n);
    for (auto &i : r)
        cin >> i;
    cin >> m;
    vector<int> b(m);
    for (auto &i : b)
        cin >> i;

    int mx1 = r[0];
    for (int i = 1; i < n; i++)
    {
        r[i] += r[i - 1];
        mx1 = max(mx1, r[i]);
    }

    int mx2 = b[0];
    for (int i = 1; i < m; i++)
    {
        b[i] += b[i - 1];
        mx2 = max(mx2, b[i]);
    }

    int ans = max({mx1, mx2, mx1 + mx2, r[n - 1], b[m - 1], r[n - 1] + b[m - 1]});
    int zero = 0;
    ans = max(ans, zero);
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
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}