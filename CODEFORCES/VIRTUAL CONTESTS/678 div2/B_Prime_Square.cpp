
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
#define int LL
#define pii pair<int, int>
#define all(a) a.begin(), a.end()
const int maxn = 1e5;
int n;
bool prime[maxn + 1];

void sieve()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                prime[j] = 0;
            }
        }
    }
}

void allOnes()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << 1 << " ";
        }
        cout << "\n";
    }
}

void fill(int x, vector<vector<int>> &arr)
{
    for (int i = 0; i < n - 1; i++)
    {
        arr[i][n - 1] = x;
        arr[n - 1][i] = x;
    }
}
void solve()
{
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 1));
    if (prime[n])
    {
        allOnes();
        return;
    }

    int filled = 1;

    if (n & 1)
    { //odd
        for (int o = 1; o <= maxn; o += 2)
        {
            if (prime[o])
                continue;
            if (prime[n - 1 + o])
            {
                filled = o;
                fill(o, arr);
                break;
            }
        }
    }
    else
    {
        for (int e = 1; e <= maxn; e++)
        {
            if (!prime[e])
            {
                if (prime[n - 1 + e])
                {
                    filled = e;
                    fill(e, arr);
                    break;
                }
            }
        }
    }

    int pre = filled * (n - 1);
    for (int i = 1; i <= maxn; i++)
    {
        if (!prime[i])
        {
            if (prime[pre + i])
            {
                arr[n - 1][n - 1] = i;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    // cout << "hello " << arr[n-1][n-1] << "\n";
}

signed main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    int t = 1;
    cin >> t;
    sieve();
    while (t--)
    {
        solve();
    }
    return 0;
}