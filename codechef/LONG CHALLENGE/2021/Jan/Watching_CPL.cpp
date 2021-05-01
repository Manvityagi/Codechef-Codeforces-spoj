#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
int h[4001];

int dp[4000][4000];
int lmt, total;
int preprocess(int curr, int curr_sum)
{
    if (curr >= lmt)
    {
        if (curr_sum >= k && total - curr_sum >= k)
            return 1;
        return 0;
    }
    if (curr_sum >= k)
    {
        if (total - curr_sum >= k)
            return 1;
        return 0;
    }
    if (~dp[curr][curr_sum])
        return dp[curr][curr_sum];
    return dp[curr][curr_sum] = (preprocess(curr + 1, curr_sum) || preprocess(curr + 1, curr_sum + h[curr]));
}

void solve()
{
    cin >> n >> k;
    int g = 0, sum = 0;
    for (auto i = 0; i < n; i++)
    {
        cin >> h[i];
        sum += h[i];
        if (h[i] >= k)
            g++;
    }
    if (sum < 2 * k)
        return void(cout << -1 << "\n");
    if (g >= 2)
        return void(cout << 2 << "\n");

    sort(h, h + n, greater<int>());

    if (g == 1)
    {
        int s = 0, one = 0;
        for (int i = 1; i < n; i++)
        {
            one++;
            s += h[i];
            if (s >= k)
                return void(cout << 1 + one << "\n");
        }
        return void(cout << -1 << "\n");
    }
    int prefixSum[n];
    prefixSum[0] = h[0];
    for (int i = 1; i < n; i++)
        prefixSum[i] = h[i] + prefixSum[i - 1];

    int ans = INT_MAX;
    int lo = 3, hi = n;

    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;
        lmt = mid;
        total = prefixSum[lmt - 1];
        for (int i = 0; i < lmt; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = -1;
        if (preprocess(0, 0))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }

    if (ans == INT_MAX)
        ans = -1;

    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}