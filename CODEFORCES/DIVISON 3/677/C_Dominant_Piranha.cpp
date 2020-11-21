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
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;

bool same(vector<int> a)
{
    int f = a[0];
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] != f)
            return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int ans;
    for (auto &i : a)
        cin >> i;
    if (same(a))
    {
        cout << -1 << "\n";
        return;
    }
    int mx = *max_element(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mx)
        {
            if ((i && a[i - 1] < a[i]) || (i != n - 1 && a[i + 1] < a[i]))
            {
                ans = i;
                break;
            }
        }
    }
    cout << 1 + ans << "\n";
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