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
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, m;
LL v, e;
vector<vector<pair<int, int>>> g;
vector<int> visited;
int total_repaired = 0;
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};
vector<vector<int>> levels(100009,vector<int>(2); //2 cols -> col1 = level no, col2 = count of repaired paths

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto node : g[front])
        {
            int dest = node.first;
            if (visited[dest])
                continue;
            int status = node.second;
            levels[dest][0] = levels[front][0] + 1;
            levels[dest][1] += levels[front][1] + status;
            q.emplace(dest);
            visited[dest] = 1;
        }
    }
}

int solve(int x)
{
    int level = levels[x][0];
    int ans = INT_MAX;

    //level-1 waalo pe jaake comparisons karne hai
    for (int i = 1; i < n; i++)
    {
        if (levels[i][0] == level - 1)
        {
            //possible candidate for shortest path
            int to_repair = levels[i][1];
            //nth aur n-1th ke beech me jo node hai wo 0 hai to to_repair += 1;

            int to_break = total_repaired - to_repair;
            if (ans < to_repair + to_break)
            {
                ans = to_repair + to_break;
            }
        }
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
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> v >> e;
        g.resize(v);
        visited.resize(v);
        for (int i = 0; i < n; i++)
        {
            int src, dest, status;
            cin >> src >> dest >> status;
            if (status)
                total_repaired++;
            g[src].emplace_back(dest, status);
            g[dest].emplace_back(src, status);
        }

        bfs(1);
        cout << solve(n);
    }
    return 0;
}
