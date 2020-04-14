#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll, ll>
main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        vector<pll> monster;
        for (int i = 0; i < n; i++)
        {
            ll a, b;
            cin >> a >> b;
            monster.push_back({a, b});
        }

        ll ans = 0;

        ans += (monster[0].first - monster[n - 1].second) > 0 ? (monster[0].first - monster[n - 1].second) : 0;
        ans += monster[0].first;
        for (int i = 2; i < n; i++)
        {
            ll val = monster[i].first - monster[i-1].second;
            ans += val > 0 ? val : 0;
        }

        cout << ans << "\n";
    }
    return 0;
}
