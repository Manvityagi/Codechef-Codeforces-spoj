#include <bits/stdc++.h>
using namespace std;
#define ll long long
main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        ll ans = 0;
        cin >> n >> x;
        vector<ll> save(n), prefix(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> save[i];
            if (save[i] >= x)
            {
                ans++;
            }
        }

        sort(save.begin(), save.end(), greater<ll>());

        prefix[0] = save[0];

        for (ll i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + save[i];
            // float curravg = (float(prefix[i])) / ((i + 1) * 1.0);
            // cout << "pre curravg " << prefix[i] << " " << curravg << "\n";
            if (prefix[i] >= x*(i+1))
            {
                ans = max(ans,i + 1);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
