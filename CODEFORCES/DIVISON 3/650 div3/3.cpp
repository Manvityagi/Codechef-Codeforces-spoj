
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
const int MAX_N = 2 * 1e5;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LL n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<int> next_one(n);
        int nex = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            next_one[i] = nex;

            if (s[i] == '1')
            {
                nex = i;
            }
        }

        int ans = 0;
        int prev_one = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (

                    (prev_one <= i - k - 1 || prev_one == INT_MAX) &&
                    (next_one[i] >= i + k + 1 || next_one[i] == -1)

                )
                {
                    prev_one = i;
                    ans++;
                }
            }
            else
            {
                prev_one = i;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
