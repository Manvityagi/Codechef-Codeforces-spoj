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
const int N = 1e5 + 10;
string a, b;
int parent[N];
int movex[] = {0, 0, 1, -1};
int movey[] = {1, -1, 0, 0};

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

void solve()
{
    cin >> n;
    cin >> a >> b;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << -1 << "\n";
            return;
        }
        union_sets(a[i] - 'a', b[i] - 'a');
    }
    vector<vector<int>> comp(n);
    for (int i = 0; i < n; i++)
    {
        int p = find_set(i);
        comp[p].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < comp.size(); i++)
    {
        if (comp[i].size() > 0)
            ans += (comp[i].size() - 1);
    }
    cout << ans << "\n";
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
        solve();
    return 0;
}
