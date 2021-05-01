
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
    string s, p;
    cin >> s >> p;
    //convert s to p
    if (s == p)
    {
        cout << "Yes\n";
        return;
    }
    int s1 = 0, s0 = 0, p1 = 0, p0 = 0;
    for (auto c : s)
    {
        if (c == '1')
            s1++;
        else
            s0++;
    }
    for (auto c : p)
    {
        if (c == '1')
            p1++;
        else
            p0++;
    }

    if ((s1 != p1) || (s0 != p0))
    {
        cout << "No\n";
        return;
    }

    bool poss = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == p[i])
            continue;
        if (s[i] == '0' && p[i] == '1')
        {
            poss = 0;
            break;
        }
    }

    if (poss)
        cout << "Yes\n";
    else
        cout << "No\n";
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