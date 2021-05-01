
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
    vector<pii> cmd(n); //ti,xi
    for (int i = 0; i < n; i++)
        cin >> cmd[i].F >> cmd[i].S;

    sort(cmd.begin(), cmd.end());

    int ans = 0, pos = 0, time = 0;

    for (int i = 0; i < n; i++)
    {
        time = cmd[i].F + (abs(cmd[i].S - pos) + 1);
        int prev = pos;
        int curr = cmd[i].S;
        ans++, i++;
        while (i < n && cmd[i].F < time)
        {
            if (cmd[i].S >= prev && cmd[i].S <= curr)
                ans++;
            i++;
        }
        pos = curr;
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