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

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    int t;
    cin >> t;

    while (t--)
    {
        int N, L;
        cin >> N >> L;

        if (N & 1)
        {
            cout << 0 << endl;
            continue;
        }

        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        for (int i = 2; i <= N; i+=2)
        {
            for (int j = 2; j <= min(L,i); j += 2)
            {
                dp[i] = dp[i] % MOD1  + dp[i - j] % MOD1  ;
            }
        }

        cout << dp[N] % MOD1 << endl;
    }
    return 0;
}
