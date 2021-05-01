
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
int n;

void solve()
{
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;

    int esum = 0, osum = 0;
    for (int i = 0; i < n; i++)
    {
        if (i & 1)
            osum += a[i];
        else
            esum += a[i];
    }

    if (esum < osum)
    {
        for (int i = 0; i < n; i += 2)
            a[i] = 1;
    }
    else
    {
        for (int i = 1; i < n; i += 2)
            a[i] = 1;
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
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