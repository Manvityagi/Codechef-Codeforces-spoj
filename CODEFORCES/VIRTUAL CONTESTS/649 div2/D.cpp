#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define F first
#define S second
const int N = 1e5 + 10;
int n, m, k, parent[N], level[N];
vector<int> g[N];

void dfs(int s)
{
    level[s] = level[parent[s]] + 1;
    for (int i : g[s])
    {
        if (i == parent[s])
            continue;
        if (level[i] == 0)
        {
            parent[i] = s;
            dfs(i);
        }
        else
        {
            int endingPoint = i;
            int cur = s;

            vector<int> ans;
            while (cur != endingPoint)
            {
                ans.emplace_back(cur);
                cur = parent[cur];
            }
            ans.push_back(endingPoint);
            cout << "2\n" << ans.size() << "\n";
            for (int i : ans)
                cout << i << " ";
            exit(0);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int src, dest;
        cin >> src >> dest;
        if (src <= k && dest <= k)
        {
            g[src].PB(dest);
            g[dest].PB(src);
        }
    }

    for (int i = 1; i <= k; i++)
    {
        if (!level[i])
            dfs(i);
    }

    vector<int> ans[2];
    for (int i = 1; i <= k; i++)
        ans[level[i] & 1].emplace_back(i);

    if (ans[0].size() < ans[1].size())
        swap(ans[1], ans[0]);

    ans[0].resize((k + 1) / 2);

    cout << 1 << "\n";
    for (int i : ans[0])
        cout << i << " ";

    return 0;
}
