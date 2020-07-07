#include <bits/stdc++.h>
using namespace std;

int helper(int n, int k, unordered_map<string, int> &dp)
{
    string q = to_string(n) + '-' + to_string(k);
    if (dp.find(q) != dp.end())
    {
        return dp[q];
    }

    if (n < 0 || k < 0)
    {
        dp[q] = 0;
        return 0;
    }

    if (n == 0 && k == 0)
    {
        dp[q] = 1;
        return 1;
    }

    if (n == 1 && k == 1)
    {
        dp[q] = 1;
        return 1;
    }

    for (int odd = 1; odd <= n; odd += 2)
    {
        bool tempans = helper(n - odd, k - 1, dp);
        if (tempans)
        {
            dp[q] = 1;
            return 1;
        }
    }

    dp[q] = 0;
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (n >= k * k && (n & 1) == (k & 1))
            cout << "YES\n";

        else
            cout << "NO\n";
    }
    return 0;
}
