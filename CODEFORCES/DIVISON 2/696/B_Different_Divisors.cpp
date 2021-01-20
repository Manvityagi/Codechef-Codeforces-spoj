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
const int maxn = 1e5 + 1;
vector<int> is_prime(maxn + 1, true);

void sieve()
{
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
                is_prime[j] = false;
        }
    }
}
void solve()
{
    int d;
    cin >> d;
    if (d == 1)
    {
        cout << 6 << "\n";
        return;
    }
    int a, one, two;
    int st = max((int)3, d+1);
    //+d ke baad i need the first prime number
    for (int i = st; i <= maxn; i++)
    {
        if (is_prime[i])
        {
            one = i;
            break;
        }
    }

    for (int i = one + d; i <= maxn; i++)
    {
        if (is_prime[i])
        {
            two = i;
            break;
        }
    }
    // cout << one << " " << two << "\n";
    a = one * two;
    cout << a << "\n";
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