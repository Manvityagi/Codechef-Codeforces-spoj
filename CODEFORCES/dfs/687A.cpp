// https://codeforces.com/contest/687/problem/A
#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
#define pii pair<int, int>
int m, n, from, to, cost;
vector<int> g[100001];
vector<int> color, visited;
bool possible = true;

bool dfs(int v)
{
    visited[v] = 1;
    for (int u : g[v])
    {
        if (!visited[u])
        {
            color[u] = !color[v];
            if (!dfs(u))
                return false;
        }
        if (color[u] != -1 && color[u] == color[v])
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m;
    color.resize(n + 1);
    visited.resize(n + 1, 0);
    fill(color.begin(), color.end(), -1);
    for (int i = 0; i < m; i++)
    {
        cin >> from >> to;
        g[from].PB(to);
        g[to].PB(from);
    }

    color[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            color[i] = 0; 
            if (!dfs(i))
            {
                cout << -1;
                return 0;
            }
        }
    }

    vector<int> set1, set2;
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 1)
        {
            set1.PB(i);
        }
        else if (color[i] == 0)
        {
            set2.PB(i);
        }
    }

    cout << set1.size() << "\n";
    for (auto a : set1)
        cout << a << " ";
    cout << "\n";
    cout << set2.size() << "\n";
    for (auto a : set2)
        cout << a << " ";
    return 0;
}
