using namespace std;
#include <bits/stdc++.h>
#define S(x) scanf("%d", &x)
#define S2(x, y) scanf("%d%d", &x, &y)
#define wl(n) while (n--)
#define ll long long
#define P(x) printf("%d\n", x)
#define PB push_back
#define MP make_pair
#define fl(i, n) for (i = 0; i < n; i++)
vector<int> v1;
pair<int, int> p1;
#define MOD 1000000007
int a[1234567];
char s[1234567];
ll pow1(ll x, ll y)
{
    if (y == 0)
        return 1;
    ll temp = pow1(x, y / 2) % MOD;
    if (y % 2 == 0)
        return (temp * temp) % MOD;
    else
        return (((temp * temp) % MOD) * x) % MOD;
}

const int N = 3e4 + 10;

vector<int> g[N];
int lev[N], vis[N];

int bfs(int n, int m)
{
    queue<int> q;
    q.push(n);
    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        if(top == m){
            return lev[top];
        }

        for (auto node : g[top])
        {
            if(!vis[node]){
                vis[node] = 1;
                q.push(node);
                lev[node] = lev[top]+1;
            }
        }
    }

    return lev[m];
}

int main()
{
    //std::ios_base::sync_with_stdio(false);
    int t, n, i, j, k, m, l;
    cin >> n >> m;

    for (int i = 1; i < N; i++)
    {
        if (i * 2 < N)
            g[i].push_back(i * 2);
        g[i].push_back(i - 1);
    }
    bfs(n, m);

    return 0;
}