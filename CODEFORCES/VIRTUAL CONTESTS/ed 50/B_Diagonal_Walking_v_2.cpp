#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    int req = max(n, m);

    if (k < req)
    {
        cout << -1 << "\n";
        return;
    }

    if (((n & 1) && !(m & 1)) || (!(n & 1) && (m & 1)))
    {
        cout << (k - 1) << "\n";
    }
    else
    {
        int rem = k - min(n, m);
        if (rem & 1)
            cout << (k - 2) << "\n";
        else
            cout << k << "\n";
    }
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}