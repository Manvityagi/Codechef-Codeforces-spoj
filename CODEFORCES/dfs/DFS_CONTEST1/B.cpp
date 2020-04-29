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
vector<int> visited, depth;
vector<int> g[100001];
int leafWithMaxDepth = 1, maxDepth;
int ans = 0;

void dfs(int st)
{
    int currans = 0;
    visited[st] = 1;
    for (auto u : g[st])
    {
        if (!visited[u])
        {
            depth[u] = 1 + depth[st];
            if (depth[u] > maxDepth)
            {
                leafWithMaxDepth = u;
                maxDepth = depth[u];
            }
            
            dfs(u);
        }
    }
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
    visited.resize(n + 1);
    depth.resize(n + 1);
    std::fill(visited.begin(), visited.end(), 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> from >> to;
        g[from].PB(to);
        g[to].PB(from);
    }
    
    dfs(1);
    std::fill(visited.begin(), visited.end(), 0);
    std::fill(depth.begin(), depth.end(), 0);
    dfs(leafWithMaxDepth);
    cout << maxDepth;

    return 0;
}
