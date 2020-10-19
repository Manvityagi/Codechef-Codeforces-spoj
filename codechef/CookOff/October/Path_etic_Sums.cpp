
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
#define eb emplace_back
#define int LL
#define all(a) a.begin(), a.end()
const int maxn = 1e5 + 1;
#define int LL
int w, n;
vector<int> g[102];

bool bipartite(int node, int currColor, vector<int> &visited, vector<int> &colors)
{
    colors[node] = currColor;
    visited[node] = 1;

    for (auto nbr : g[node])
    {
        if (visited[nbr] && colors[nbr] == currColor)
            return false;
        if (visited[nbr])
            continue;
        if (!bipartite(nbr, !currColor, visited, colors))
            return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        g[i].clear();

    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }
    vector<int> visited(n + 1, 0), colors(n + 1, -1), ans(n + 1);
    bipartite(1, 0, visited, colors);

    for (int i = 1; i <= n; i++)
    {
        if (colors[i])
            ans[i] = 7;
        else
            ans[i] = 6;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
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