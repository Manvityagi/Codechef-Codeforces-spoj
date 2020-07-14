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

signed main()
{
    static const LL _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL t = 1;
    cin >> t;
    while (t--)
    {
        LL n, x;
        cin >> n >> x;
        vector<LL> a(n);
        for (auto &i : a)
            cin >> i;
            
        sort(a.begin(), a.end());
        LL curr_sz = 1, ans = 0;
        LL mn_till_now = a[0];
        for (LL i = n - 1; i >= 0; i--)
        {
            if (a[i] >= x)
            {
                ans++;
                curr_sz = 1;
                continue;
            }

            if (curr_sz * a[i] >= x)
            {
                ans++;
                curr_sz = 1;
            }
            else
            {
                curr_sz++;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
