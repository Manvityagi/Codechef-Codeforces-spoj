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
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<LL> s(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        int ans = 1;
        vector<int> dp(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * i <= n; j++)
            {
                int add = dp[j * i] > dp[i] ? 1 : 0;
                if (add)
                    dp[j * i] = max(dp[j * i], 1 + dp[i]);
            }

            ans = max(ans, dp[i]);
        }
        cout << ans << "\n";
    }
    return 0;
}