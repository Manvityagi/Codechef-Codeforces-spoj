#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007

vector<ll> graph[10001];
ll visited[10001];
ll ans, parent;
ll q, a, b;

void dfs(ll start)
{
    visited[start] = 1;
    if (start == b)
    {
        ans = 1;
    }
    for (auto i : graph[start])
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }
}

int main()
{
    ll n;
    cin >> n;
    memset(visited, 0, sizeof(visited));
    ll node = 0;
    vector<pair<ll, ll>> v;
    v.push_back({0, 0});
    for (ll i = 0; i < n; i++)
    {
        cin >> q >> a >> b;
        if (q == 1)
        {
            node++;
            v.push_back(make_pair(a, b));
            if (node != 1)
            {
                for (ll i = 1; i < node; i++)
                {
                    ll c = v[i].first;
                    ll d = v[i].second;
                    if ((c < a && a < d) || (c < b && b < d))
                    {
                        graph[node].push_back(i);
                        graph[i].push_back(node);
                    }
                }
            }
        }
        else
        {
            memset(visited, 0, sizeof(visited));
            ans = 0;
            dfs(a);
            if (ans)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}