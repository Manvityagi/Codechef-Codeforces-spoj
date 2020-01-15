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
#define INF LONG_MAX
#define pr(i, x, n)                    \
    for (int ii = i; ii < n + i; ii++) \
    {                                  \
        cout << x[ii] << " ";          \
    }                                  \
    cout << endl;
#define ip(i, x, n)                    \
    for (int ii = i; ii < n + i; ii++) \
    {                                  \
        cin >> x[ii];                  \
    };
#define db(x, y) cout << x << " " << y << endl;
#define LD long double
#define PR pair<LD, LL>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
        k
    }();

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        std::vector<vector<int>> mat(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }

        int ans = m * n, center;

        //pick each element as center,
        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                center = mat[i][j];

                int up = i, down = i, left = j, right = j;
                while (up > 0 && down < n && left > 0 && right < m)
                {

                    if (mat[up][j] == mat[down][j] && mat[i][left] == mat[i][right])
                    {
                        up++;
                        down--;
                        left--;
                        right++;

                        ans++;
                    }
                }
            }
        }

        return ans;
    }
    return 0;
}