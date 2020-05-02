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

    cin >> n;
    visited.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> from >> to;
        from--, to--;
        g[from].PB(i);
        g[to].PB(i);
    }

    vector<int> answer(n,-1);
    int at = 0;

    for (int i = 0; i < n; i++)
    {
        if (g[i].size() >= 3)
        {
            answer[g[i][0]] = 0;
            answer[g[i][1]] = 1;
            answer[g[i][2]] = 2;
            at = 3;
            break;
        }
    }

    for(int i = 1; i < n; i++)
    {
        if(answer[i] == -1){
            answer[i] = at;
            at++;
        }
    }

     for(int i = 1; i < n; i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}
