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
#define int LL
const int N = 1e6 + 5;
int sieve[N];

void countPrimes()
{
    sieve[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!sieve[i])
        {
            for (int j = i * 2; j < N; j += i)
            {
                sieve[j] = 1;
            }
        }
    }
    for (int i = 1; i < N; i++)
    {
        sieve[i] = !sieve[i] + sieve[i - 1];
    }
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
    countPrimes();
    while (t--)
    {
        LL n;
        cin >> n;
        if (n == 0 || n == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        else if (n == 2)
        {
            cout << 1 << "\n";
            continue;
        }
        LL ans = sieve[n] + n - 3;
        cout << ans << "\n";
    }
    return 0;
}
