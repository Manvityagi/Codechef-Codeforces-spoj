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
    unordered_set<int> g[n + 1];
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace(v);
        g[v].emplace(u);
    }
    int ans = 0;
    // for(int i = 1; i <= n; i++){
    //     cout << i << ":";
    //     for(auto j : g[i]){
    //         cout << j << " "; 
    //     }
    //     cout << "\n"; 
    // }
    for(int i = 1; i <= n; i++){
        // cout << i << ": " << g[i].size() << "\n";
        if(g[i].size() == 1) ans++;
    }
    cout << ans;
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