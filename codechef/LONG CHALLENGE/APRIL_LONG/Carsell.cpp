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

void erast()
{
    int n;
    vector<char> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (is_prime[i] && (long long)i * i <= n)
        {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

static bool sortByVal(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
        return (a.second < b.second);
    else
        return (a.first < b.first);
}

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
        LL n;
        cin >> n;
        vector<LL> price(n);

        for (int i = 0; i < n; i++)
        {
            cin >> price[i];
        }

        sort(price.begin(), price.end(), greater<int>());
        LL ans = 0;
        for (int i = 0; i < n; i++)
        {

            if (price[i] - i > 0)
            {
                ans = (ans%MOD1 + (price[i] - i))%MOD1;
            }
        }

        cout << ans%MOD1 << "\n";
    }
    return 0;
}
