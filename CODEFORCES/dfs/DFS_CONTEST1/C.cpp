// https://codeforces.com/gym/278148/problem/C
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
int m, n, from, to, cost;
int movex[] = {-1, 1, 0, 0};
int movey[] = {0, 0, -1, 1};
vector<int> visited, cat;
vector<int> g[100001];
int ans = 0;

int dfs(int st)
{
    int currans = 0;
    visited[st] = 1;
    for (auto u : g[st])
    {
        if (!visited[u])
            currans = max(currans, 1 + dfs(u));
    }

    return currans;
}

int main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();

    cin >> n >> m;
    visited.resize(n + 1), cat.resize(n + 1);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> cat[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> from >> to;
        g[from].PB(to);
        g[to].PB(from);
    }

    dfs(1);

    cout << ans;
    return 0;
}
