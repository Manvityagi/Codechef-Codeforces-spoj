
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
vector<int> w;
vector<int> g[100001];
int n;

void helper(int curr)
{
    vector<int> res;
    priority_queue<pii> maxpq;

    for (int i = 1; i <= n; i++)
    {
        int sz = g[i].size();
        if (sz != 1)
        {
            sz--;
            maxpq.emplace(w[i], sz);
        }
    }

    for (int i = 1; i <= n - 1; i++)
    {
        res.emplace_back(curr);

        if (maxpq.size() > 0)
        {
            auto front = maxpq.top();
            maxpq.pop();
            int add = front.F;
            if (front.S > 1)
            {
                maxpq.emplace(add, front.S - 1);
            }

            curr += add;
        }
    }

    for (auto i : res)
        cout << i << " ";
    cout << "\n";
}

void solve()
{
    cin >> n;
    w.clear();
    w.resize(n + 1);
    int curr = 0;
    for (auto i = 1; i <= n; i++)
    {
        cin >> w[i];
        curr += w[i];
    }
    for (int i = 0; i <= n; i++)
        g[i].clear();
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    helper(curr);
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