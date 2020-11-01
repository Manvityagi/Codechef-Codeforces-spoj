#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define MOD 1000000007
#define clr(a) memset(a, 0, sizeof(a))
#define len(x) x.size()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define allv(v) v.begin(), v.end()
#define alla(a, n) a, a + n

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<string> vs;

int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // __init_nCr()  ;
    // __init_fact() ;

    int t;
    cin >> t;

    while (t-- != 0)
    {
   
        int n;
        ll p;
        cin >> n >> p;
        vector<ll> v(n);
        for (auto i = 0; i < n; ++i)
            cin >> v[i];

        if (n == 1)
        {
            if (p % v[0])
            {
                cout << "YES " << (p / (v[0])) + 1 << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            continue;
        }

    

        // 2. if all mod 0 then :

        vll ans(n, 0);

        // cout << "v[i]  q  p\n\n" ;
        bool found = false;
        for (int i = n - 1; i >= 0; --i)
        {

            ll q = p / v[i];

            if (v[i] * q == p)
            {
                --q;
            }
            else
            {
                ++q;
                found = true;
            }
            ans[i] = q;
            p -= (v[i] * q);

            if (found)
                break;
        }

        if (found)
        {
            cout << "YES ";
            for (auto i : ans)
                cout << i << ' ';
        }
        else
            cout << "NO";

        cout << endl;
    }

    return 0;
}