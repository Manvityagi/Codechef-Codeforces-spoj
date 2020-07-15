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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0, j = i + gap; i < n, j < n; i++, j++)
            {
                if (!(gap & 1))
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if (s[i] == ')' || s[j] == '(')
                    {
                        dp[i][j] = 0;
                    }
                    else if ((s[i] == '(' && (s[j] == ')' || s[j] == '?')) ||
                             (s[i] == '?' && (s[j] == ')' || s[j] == '?')))
                    {
                        if (gap == 1)
                            dp[i][j] = 1;
                        else
                            dp[i][j] = dp[i + 1][j - 1];

                        //i+1 = ) && j-1 == (

                        if (gap >= 3)
                        {
                            if ((s[i + 1] == ')' || s[i + 1] == '?') &&
                                (s[j - 1] == '(' || s[j - 1] == '?'))
                            {
                                if (gap == 3)
                                {
                                    dp[i][j] = 1;
                                }
                                else
                                {
                                    if (i + 2 < n && j - 2 >= 0)
                                        dp[i][j] = dp[i + 2][j - 2];
                                }
                            }
                        }
                    }
                }

                ans += dp[i][j];
            }
        }

        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = 0; j < n; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        cout << ans << "\n";
    }
    return 0;
}
