// https://codeforces.com/gym/278148/problem/C
#include <bits/stdc++.h>
#define PB push_back
using namespace std;
int n,from,to;
vector<int> visited, dp, depth[100001];
vector<int> g[100001];
int ans = 0;

void dfs(int st)
{
    dp[st] = 1;
    visited[st] = 1;
    for (auto u : g[st])
    {
        if (!visited[u])
        {
            dfs(u);
            dp[st] += dp[u];
        }
    }
}

int main()
{
    cin >> n;
    if (n & 1) return cout << -1, 0;

    int leafnode = 1;
    visited.resize(n + 1);
    dp.resize(n + 1);
    fill(visited.begin(), visited.end(), 0);
    for (int i = 1; i < n; i++)  {
        cin >> from >> to;
        g[from].PB(to);
        g[to].PB(from);
    }
    
    for(int i = 1; i <= n; i++){
    	if(g[i].size() == 1){
    		leafnode = i;
    		break;
    	}
    }
    dfs(leafnode);
    for (int i = 1; i <= n; i++) {
        if (g[i].size() > 1 && !(dp[i] & 1))
            ans++;
    }
    cout << ans;
    return 0;
}
