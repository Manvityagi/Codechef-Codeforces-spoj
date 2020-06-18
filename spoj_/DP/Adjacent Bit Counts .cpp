#include <bits/stdc++.h>
using namespace std;
int ds, n, k;

main()
{
    int t;
    cin >> t;
    int dp[10000][10000][2] = {0};
    dp[1][0][0] = 1;
    dp[1][1][0] = 0;
    dp[1][0][1] = 1;
    dp[1][1][1] = 0;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];

            if (j >= 1)
                dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
            else
                dp[i][j][1] = dp[i - 1][j][0];
        }
    }
    while (t--)
    {

        cin >> ds >> n >> k;

        if (k >= n)
        {
            cout << ds << " " << 0 << "\n";
            continue;
        }

        cout << ds << " " << dp[n][k][0] + dp[n][k][1] << "\n";
    }
    return 0;
}
