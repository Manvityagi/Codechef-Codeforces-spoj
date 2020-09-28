#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define F first
#define S second
#define MP make_pair
const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
vector<pair<int, pair<int, int>>> edges;

void bfs(int src, vector<int> &dis, vector<int> &cnt)
{
    dis[src] = 0;
    queue<int> q;
    q.emplace(src);
    while (q.size())
    {
        int src = q.front();
        q.pop();
        for (auto &p : g[src])
        {
            int dest = p.F, status = p.S;
            if (~dis[dest])
                continue;
            dis[dest] = dis[src] + 1;
            cnt[dest] = cnt[src] + status;
            q.emplace(dest);
        }
    }
}

main()
{
    static const int _ = []() {
        ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        return 0;
    }();
    LL v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int src, dest, status;
        cin >> src >> dest >> status;
        g[src].emplace_back(dest, status);
        g[dest].emplace_back(src, status);
        edges.emplace_back(MP(status, MP(src, dest)));
    }
    //dis[0] = vector containing distances of each node from 1st node
    //dis[1] = vector conatining distance of each node from nth node

    //cnt[0] = count of good roads from 1 to i
    //cnt[1] = count of bad roads from n to i

    vector<int> dis[2], cnt[2];
    for (int i = 0; i <= 1; i++)
    {
        dis[i] = vector<int>(v + 1, -1);
        cnt[i] = vector<int>(v + 1, 0);
    }

    bfs(1, dis[0], cnt[0]);
    bfs(v, dis[1], cnt[1]);

    vector<int> parent(v + 1, -1);

    int src = 1;
    for (int distance = dis[1][1] - 1; distance >= 0; distance--)
    {
        int tmp, good_roads = -1;
        for (auto &p : g[src])
        {
            int dest = p.F;
            if (parent[src] == dest)
            {
                continue;
            }
            if (dis[1][dest] == distance && cnt[0][dest] + cnt[1][dest] > good_roads)
            {
                good_roads = cnt[0][dest] + cnt[1][dest];
                tmp = dest;
            }
        }
        parent[tmp] = src;
        src = tmp;
    }

    vector<pair<pair<int, int>, int>> ans;
    for (auto p : edges)
    {
        auto edge = p.S;
        auto status = p.F;
        if (parent[edge.first] == edge.second || parent[edge.second] == edge.first)
        {
            if (!status)
            {
                ans.emplace_back(edge, 1);
            }
        }
        else if (status)
        {
            ans.emplace_back(edge, 0);
        }
    }

    cout << ans.size() << "\n";
    for (auto &e : ans)
        cout << e.F.F << " " << e.F.S << " " << e.S << "\n";
    return 0;
}