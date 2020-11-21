
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
vector<int> g[maxn];

//mex,subtreeSize
pair<int, int> dfs(int node)
{
    if (g[node].size() == 0)
        return {1, 1};

    auto ans = MP(0LL, 0LL);
    for (auto nbr : g[node])
    {
        auto curr = dfs(nbr);
        ans.S += curr.S;
        if (curr.F > ans.F)
        {
            ans.F = curr.F;
        }
    }
    ans.S += 1;
    ans.F = ans.S + ans.F;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)
        g[i].clear();
    for (int i = 1; i <= n - 1; i++)
    {
        int p;
        cin >> p;
        // g[i+1].emplace_back(p);
        g[p].emplace_back(i + 1);
    }

    cout << dfs(1).F << "\n";
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