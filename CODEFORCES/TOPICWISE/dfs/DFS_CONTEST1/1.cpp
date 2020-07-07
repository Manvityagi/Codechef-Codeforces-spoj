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
#define pii pair<int, int>

int n, from, to, cost;
int movex[] = {-1, 1, 0, 0};
int movey[] = {0, 0, -1, 1};
vector<int> visited;
vector<pii> g[101];
int ans = 0;
int dfs(int st)
{
    int currans = 0;
    visited[st] = 1;
    for (auto u : g[st])
    {
        int dest = u.F, cost = u.S;
        if (!visited[dest])
            ans = max(ans, cost + dfs(dest));
    }

    return ans;
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> n;
    visited.resize(n);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> from >> to >> cost;
        g[from].PB(MP(to, cost));
        g[to].PB(MP(from, cost));
    }

    dfs(0);

    return 0;
}
