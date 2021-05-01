
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
    string s;
    cin >> s;
    int n = s.size(), one = 0, zero = 0;
    for (auto c : s)
    {
        if (c == '1')
            one++;
        else
            zero++;
    }
    if (n & 1 || !one || !zero)
    {
        cout << -1 << "\n";
        return;
    }

    int ans = n / 2 - min(zero,one);

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