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
vector<int> g[150005];
int leafWithMaxDepth = 1, maxDepth;
int ans = 0;
unordered_set<string> edges;

void dfs(int st, int &vertexcount)
{
    // cout << "DFS " << st << "\n";
    vertexcount++;
    visited[st] = 1;
    for (auto u : g[st])
    {
        if (u < st)
        {
            edges.insert(to_string(u) + to_string(st));
        }
        else
        {
            edges.insert(to_string(st) + to_string(u));
        }

        if (!visited[u])
        {
            dfs(u, vertexcount);
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
    for (int i = 1; i <= m; i++)
    {
        cin >> from >> to;
        g[from].PB(to);
        g[to].PB(from);
    }

    fill(visited.begin(), visited.end(), 0);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int vertexcount = 0, edgecount = 0;
            edges.clear();
            dfs(i, vertexcount);
            edgecount = edges.size();
            // cout << i << " " << vertexcount << " " << edgecount << "\n";
            if (edgecount != (vertexcount * (vertexcount - 1)) / 2)
            {
                return cout << "NO", 0;
            }
        }
    }
    cout << "YES";
    return 0;
}
