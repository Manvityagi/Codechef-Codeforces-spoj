#include "bits/stdc++.h"
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define int long long int
#define fora(i, n) for (int i = 0; i < n; i++)
#define dbg(x)                             \
    {                                      \
        cout << #x << ": " << (x) << '\n'; \
    }
#define dbg2(x, y)                                                       \
    {                                                                    \
        cout << #x << ": " << (x) << " , " << #y << ": " << (y) << '\n'; \
    }
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n, k, limit;
vector<int> height;
int dp[4000][4000];
int rec(int idx, int sum)
{
    if (sum >= k)
    {
        if (limit - sum >= k)
        {
            // cout<<"YESS\n";
            return 0;
        }
        return INT_MAX;
    }
    if (idx >= n)
    {
        if (sum >= k)
        {
            if (limit - sum >= k)
            {
                return 0;
            }
            return INT_MAX;
        }
        return INT_MAX;
    }
    if (~dp[idx][sum])
        return dp[idx][sum];
    return dp[idx][sum] = min(rec(idx + 1, sum), 1 + rec(idx + 1, sum + height[idx]));
}
void test_case()
{
    cin >> n >> k;
    height.clear();
    height.resize(n);
    fora(i, n) cin >> height[i];
    sort(all(height));
    // int cnt = 0;
    // int sm = accumulate(all(height), 0LL);
    int big = 0;
    for (auto ele : height)
        big += (ele >= k);
    if (big >= 2)
    {
        cout << 2 << "\n";
    }
    else if (big == 1)
    {
        int other = 0;
        int smm = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (smm >= k)
                break;
            smm += height[i];
            other++;
        }
        if (smm < k)
            cout << -1 << "\n";
        else
            cout << 1 + other << "\n";
    }
    else
    {
        // all elements less than k
        int ans = -1;
        reverse(all(height));
        int pref[n];
        pref[0] = height[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + height[i];
        int l = 1, r = n;
        limit = pref[n - 1];
        // memset(dp,-1,sizeof(dp));
        // int x = rec(0,0);

        // cout<< x << "\n";
        if (accumulate(all(height), 0LL) < 2 * k)
        {
            cout << -1 << "\n";
            return;
        }
        bool fl = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            // mid number of boxes
            limit = pref[mid - 1];
            n = mid;
            // memset(dp, -1, sizeof(dp));
            fora(i, mid)
            {
                fora(j, k + 1) dp[i][j] = -1;
            }
            int net = rec(0, 0);
            if (net < INT_MAX)
            {
                // dbg(net);
                fl = 1;
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        if (!fl)
            cout << -1 << "\n";
        else
            cout << ans << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        test_case();
    }
}