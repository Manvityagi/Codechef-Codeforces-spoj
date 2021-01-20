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
    string b;
    cin >> b;
    string ans = "1";
    for (int i = 1; i < n; i++)
    {
        if ((b[i - 1] == '0' && ans[i - 1] == '1') || (b[i - 1] == '1' && ans[i - 1] == '0'))
        {
            ans += b[i];
        }
        else if (b[i - 1] == '1' && ans[i - 1] == '1')
        {
            if (b[i] == '1')
                ans += '0';
            else
                ans += '1';
        }
        else
        {
            ans += '1';
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