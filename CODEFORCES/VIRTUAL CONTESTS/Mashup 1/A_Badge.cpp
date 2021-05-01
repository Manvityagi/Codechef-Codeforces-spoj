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
vector<int> g[1001];
vector<int> p;

void dfs(int src, vector<int> &vis)
{
    if (vis[src])
    {
        cout << src << " ";
        return;
    }
    vis[src] = 1;
    dfs(p[src], vis);
}

void solve()
{
    int n;
    cin >> n;
    p.resize(n + 1);
    for (auto i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = 1; i <= n; i++)
    {
        vector<int> vis(n+1, 0);
        dfs(i, vis);
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
    // cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}