//https://codeforces.com/contest/1343/problem/E
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int t, n, m, a, b, c, from, to;
vector<int> price, prefix;

void bfs()
{
}

void solve()
{
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    vector<vector<int>> g(n);
    price.resize(m);
    prefix.resize(m);
    sort(price.begin(), price.end());
    prefix[0] = price[0];
    for (int i = 1; i <= m; i++)
    {
        prefix[i] = price[i] + prefix[i - 1];
    }

    for(int i = 1; i <= m; i++)
    {
        cin >> from >> to;
        g[from].pb(to);
        g[to].pb(from);
    }

     
}

int main()
{
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}