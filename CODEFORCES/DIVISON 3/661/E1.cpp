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
#define pll pair<LL,LL> 
#define pii pair<int,int> 
#define loop(i, a, b) for (int i = a; i < b; i++)
LL n, s;
int movex[] ={ 0, 0, 1, -1 };
int movey[] ={ 1, -1, 0, 0 };
const LL N = 1e5+10;
vector<pii> g[N];
vector<int> visited;
#define pii pair<int,int>
unordered_map<pii, int> mp; //how many times, each edge occurs 

void dfs(int u)
{
    for (auto v : g[u])
    {
        int dest = v.F, wt = v.S;
        if (!visited[dest]) {
            dfs(dest);
            visited[dest] = 1;
        }
        // mp[MP(u,v)]++;
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
    int t = 1;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        visited.resize(n);
        fill(visited.begin(), visited.end(), 0);
        for (int i=0;i<n;i++) {
            LL u, v, w;
            cin >> u >> v >> w;
            g[u].emplace_back(v, w);
        }
        //root to each(leaf) jaana hai 
        dfs(1);




    }
    return 0;
}
