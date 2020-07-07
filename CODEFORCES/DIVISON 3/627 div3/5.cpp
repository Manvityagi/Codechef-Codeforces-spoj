#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define fastIO                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define nl "\n"
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
using namespace std;

li dp[2000][2000];

li sleepingRecursive(li arr[], li n, li h, li l, li r, li s, li i)
{
    if (i >= n)
        return (s >= l && s <= r);
    if (dp[i][s] != -1)
        return dp[i][s];
    if (s >= l && s <= r)
        dp[i][s] = 1 + max(sleepingRecursive(arr, n, h, l, r, (s + arr[i]) % h, i + 1), sleepingRecursive(arr, n, h, l, r, (s + arr[i] - 1) % h, i + 1));
    else
        dp[i][s] = max(sleepingRecursive(arr, n, h, l, r, (s + arr[i]) % h, i + 1), sleepingRecursive(arr, n, h, l, r, (s + arr[i] - 1) % h, i + 1));
    return dp[i][s];
}

int main()
{
    li n, h, l, r, i, j;
    cin >> n >> h >> l >> r;
    li arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < h; j++)
            dp[i][j] = -1;
    cout << max(sleepingRecursive(arr, n, h, l, r, arr[0], 1), sleepingRecursive(arr, n, h, l, r, arr[0] - 1, 1));
}