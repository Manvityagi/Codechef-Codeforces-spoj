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
        vector<vector<int>> dp1(n + 1, vector<int>(n + 1, 0));
        vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 0));
        int ans = 0, l, r;

        //left to right
        for (l = 0; l < n; l++)
        {
            int cnt = 0;
            bool ok = 1;
            for (r = l; r < n; r++)
            {
                if (s[r] == ')')
                {
                    cnt--;
                }
                else
                {
                    cnt++;
                }

                if (cnt < 0)
                {
                    ok = 0;
                }
                dp1[l][r] = ok;
            }
        }

        // right to left
        for (r = 0; r < n; r++)
        {
            int cnt = 0;
            bool ok = 1;
            for (l = 0; l < r; l++)
            {
                if (s[l] == '(')
                {
                    cnt--;
                }
                else
                {
                    cnt++;
                }

                if (cnt < 0)
                {
                    ok = 0;
                }
                dp2[l][r] = ok;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp1[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "\n";

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dp2[i][j] << " ";
            }
            cout << "\n";
        }

        for (int l = 0; l < n; l++)
        {
            for (int r = 0; r < n; r++)
            {
                if (dp1[l][r] && dp2[l][r] && (r - l + 1) % 2 == 0)
                {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
