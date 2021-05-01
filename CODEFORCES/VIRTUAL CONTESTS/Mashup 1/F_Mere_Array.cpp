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

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &i : p)
        cin >> i;
    vector<int> o = p;
    int mn = *min_element(p.begin(), p.end());
    sort(p.begin(), p.end());
    bool poss = 1;
    for (int i = 0; i < n; i++)
    {
        if (o[i] == p[i])
            continue;
        if (o[i] % mn)
        {
            poss = 0;
            break;
        }
    }
    if (poss)
        cout << "YES\n";
    else
        cout << "NO\n";
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

    while (t--)
    {
        solve();
    }
    return 0;
}