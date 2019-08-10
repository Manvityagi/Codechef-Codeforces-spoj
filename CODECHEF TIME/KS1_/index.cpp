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
#define N 400100
#define LD long double
#define PR pair<LD, LL>

vector<vector<int>> xorfunc(vector<int> input)
{
    int n = input.size();
    vector<vector<int>> calxor(n, vector<int>(n));
    // cout << "calculating CALXOR " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == j)
                calxor[i][j] = input[i];
            else if (j - i == 1)
                calxor[i][j] = input[i] ^ input[j];
            else if (i < j)
                calxor[i][j] = calxor[i][j - 1] ^ input[j];

            // cout << i << " " << j << " " << calxor[i][j] << endl;
        }
    }

    return calxor;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> input(n);
        for (int i = 0; i < n; i++)
            cin >> input[i];

        //simply make a dp[start][end] storing xors
        vector<vector<int>> calxor(n, vector<int>(n));
        calxor = xorfunc(input);

        // cout << "printing calxor" << endl;
        // 	 for(int i = 0; i < calxor.size(); i++) {
        // 	     for(int j = 0; j < calxor[0].size(); j++) {
        // 	         // cout << calxor[i][j] << " ";
        // 	     }
        // cout << endl;
    // }
    // cout << endl;
    int ans = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < k; i++)
        {
            if (calxor[i][k] == 0)
                ans += k - i;
        }
    }
    cout << ans << endl;
}
return 0;
}
