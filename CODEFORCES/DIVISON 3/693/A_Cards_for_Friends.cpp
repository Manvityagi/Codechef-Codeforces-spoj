
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
    int w, h, n;
    cin >> w >> h >> n;
    if (n <= 1)
    {
        cout << "YES\n";
        return;
    }
    int cnt = 1;
    while (w > 0 && w % 2 == 0)
    {
        w /= 2;
        cnt *= 2;
    }

    while (h > 0 && h % 2 == 0)
    {
        h /= 2;
        cnt *= 2;
    }

    if (cnt >= n)
        cout << "YES\n";
    else
        cout << "NO\n";
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