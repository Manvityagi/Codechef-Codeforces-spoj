#include <bits/stdc++.h>
#define PB push_back
using namespace std;
int n, m, from, to;
vector<int> visited, ans;
unordered_set<int> box;
vector<int> g[100002];

priority_queue<int, vector<int>, greater<int>> pq;

void graphinput()
{
    cin >> n >> m;

    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);
    for (int i = 1; i <= m; i++)
    {
        cin >> from >> to;
        g[from].PB(to);
        g[to].PB(from);
    }
}

void solve()
{
    pq.emplace(1);

    while (!pq.empty())
    {

        int top = pq.top();
        ans.push_back(top);
        visited[top] = 1;
        pq.pop();
        for (auto u : g[top])
        {
            if (!visited[u])
            {
                pq.emplace(u);
                visited[u] = 1;
            }
        }
    }
}

int main()
{

    graphinput();

    solve();

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
