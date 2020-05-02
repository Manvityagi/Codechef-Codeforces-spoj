#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair
#define ll long long
#define Ull unsigned long long
#define LB lower_bound
#define MOD1 1000000007
#define MOD2 1000000009
ll m, n;
void hello()
{
    for(ll i = 0; i < 5; i++){

    }
}
vector<ll> arr;
ll main()
{
  
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        hello();

        if (n == 2)
        {
            cout << 2 << "\n";
            continue;
        }

        ll sum = (1LL << n);
        for (ll i = 1; i < n; ++i)
        {
            sum -= (1LL << i);
        }
        for (ll i = 1; i < n / 2; ++i)
        {
            sum += (1LL << (i + 1));
        }
        cout << sum << "\n";
    }
    return 0;
}
