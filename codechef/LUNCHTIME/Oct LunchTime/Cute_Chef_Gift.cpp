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
const int maxn = 1e5 + 5;
int spf[maxn], prime[maxn];
void sieve()
{
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 0; i < maxn; i++)
        spf[i] = i;
    for (int i = 2; i * i <= maxn; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= maxn; j += i)
            {
                if (prime[j])
                    spf[j] = i;
                prime[j] = 0;
            }
        }
    }
}

vector<int> getFactors(int x)
{
    vector<int> factors;
    while (x != 1)
    {
        factors.emplace_back(spf[x]);
        x /= spf[x];
    }
    return factors;
}

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, pii> ranges; //unsafe ranges
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vector<int> factors = getFactors(num);
        for (auto f : factors)
        {
            if (ranges.find(f) == ranges.end())
            {
                ranges[f] = MP(i, i);
            }
            else
            {
                ranges[f].S = i;
            }
        }
    }
    vector<int> diff(n + 1, 0);
    for (auto p : ranges)
    {
        int l = p.S.F, r = p.S.S;
        diff[l]++;
        diff[r]--;
    }

    for (int i = 1; i < n; i++)
        diff[i] += diff[i - 1];

    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (diff[i] == 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans+1 << "\n";
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