
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
    int n;
    cin >> n;
    vector<int> x(n);
    unordered_map<int, int> mp;
    for (auto &i : x)
    {
        cin >> i;
        mp[i]++;
    }
    sort(x.begin(), x.end());

    if (n == 1)
    {
        cout << 1 << "\n";
        return;
    }
    int ans = 0;
    int pre = 0;
    for (auto i = 0; i < n; i++)
    {
        if (pre == x[i])
        {
            ans++;
            pre = x[i] + 1;
        }
        else if (pre < x[i])
        {
            ans++;
            pre = x[i];
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
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}