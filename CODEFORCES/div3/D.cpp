
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
char a[MAX_N];

void findminmax(LL dig, LL &mn, LL &mx)
{
    while (dig > 0)
    {
        LL curr = dig % 10;
        mn = min(curr, mn);
        mx = max(curr, mx);
        dig /= 10;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        LL n, k, mx = 1;
        scanf("%ld%ld", &n, &k);
        LL ans = LONG_MAX;

        for (int i = 1; i * i <= n && i <= k; ++i)
        {
            if (n % i)
                continue;
            if (n / i <= k)
            {
                mx = n / i;
                break;
            }
            mx = i;
        }
        cout << n / mx << "\n";
    }

    return 0;
}
